#include "QrocoDetectorConstruction.hh"
#include "QrocoDetectorMessenger.hh"

#include "QrocoScintSD.hh"
#include "QrocoPmtSD.hh"

#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4MaterialTable.hh"
#include "G4Element.hh"
#include "G4Isotope.hh"
#include "G4UnitsTable.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Sphere.hh"
#include "G4UnionSolid.hh"
#include "G4SubtractionSolid.hh"

#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4ThreeVector.hh"
#include "G4RotationMatrix.hh"
#include "G4Transform3D.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4OpBoundaryProcess.hh"

#include "G4FieldManager.hh"
#include "G4UniformElectricField.hh"
#include "G4TransportationManager.hh"
#include "G4MagIntegratorStepper.hh"
#include "G4EqMagElectricField.hh"
#include "G4ClassicalRK4.hh"
#include "G4ChordFinder.hh"

#include "G4SDManager.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"

#include "G4UserLimits.hh"

#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "CADMesh.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
QrocoDetectorConstruction::QrocoDetectorConstruction()  
{
   // create commands for interactive definition of time cuts:
   detectorMessenger = new QrocoDetectorMessenger(this);

   theUserLimitsForRoom     = 0; 
   theUserLimitsForDetector = 0; 
   // default time cut = infinite
   //  - note also number of steps cut in stepping action = MaxNoSteps
   theMaxTimeCuts      = DBL_MAX;
   theMaxStepSize      = DBL_MAX;
   theDetectorStepSize = DBL_MAX;
   theRoomTimeCut      = 1000. * nanosecond;
   theMinEkine         = 250.0*eV; // minimum kinetic energy required in volume
   theRoomMinEkine     = 250.0*eV; // minimum kinetic energy required in volume
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
QrocoDetectorConstruction::~QrocoDetectorConstruction() 
{
   delete theUserLimitsForRoom;
   delete theUserLimitsForDetector;
   delete detectorMessenger;
}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
void QrocoDetectorConstruction::DefineMaterials() 
{
   #include "QrocoDetectorMaterial.icc"
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
G4VPhysicalVolume* QrocoDetectorConstruction::Construct() {

   G4NistManager* nist = G4NistManager::Instance();
   DefineMaterials();

   // make colours
   G4Colour  white   (1.0, 1.0, 1.0) ;
   G4Colour  grey    (0.5, 0.5, 0.5) ;
   G4Colour  lgrey   (.85, .85, .85) ;
   G4Colour  red     (1.0, 0.0, 0.0) ;
   G4Colour  blue    (0.0, 0.0, 1.0) ;
   G4Colour  cyan    (0.0, 1.0, 1.0) ;
   G4Colour  magenta (1.0, 0.0, 1.0) ; 
   G4Colour  yellow  (1.0, 1.0, 0.0) ;
   G4Colour  orange  (.75, .55, 0.0) ;
   G4Colour  lblue   (0.0, 0.0, .75) ;
   G4Colour  lgreen  (0.0, .75, 0.0) ;
   G4Colour  green   (0.0, 1.0, 0.0) ;
   G4Colour  brown   (0.7, 0.4, 0.1) ;
   
   
   //Find materials
   G4Material* Al = nist->FindOrBuildMaterial("G4_Al");

   // Universe - room wall - CONCRETE ****************************************

   //NB: measured INSIDE of lab, therefore have to add twice wall thickness
   G4double wallThick   = 24.*cm;
   G4double worldWidth  = 470.0*cm + 2.*wallThick; // "x"
   G4double worldLength = 690.0*cm + 2.*wallThick; // "y"
   G4double worldHeight = 280.0*cm + 2.*wallThick; // "z"

   G4Box* world_box = new G4Box("world_box", 0.5*worldWidth, 0.5*worldLength, 0.5*worldHeight );
   world_log  = new G4LogicalVolume(world_box, world_mat, "world_log");
   world_phys = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.),"world_phys", world_log, NULL, false,0);

   world_log->SetVisAttributes(G4VisAttributes::GetInvisible());
  
   // Lab Space - AIR ********************************************************

   G4double labWidth  = worldWidth  - 2.*wallThick; //X
   G4double labLength = worldLength - 2.*wallThick; //Y
   G4double labHeight = worldHeight - 2.*wallThick; //Z

   G4Box* lab_box = new G4Box("lab_box", 0.5*labWidth, 0.5*labLength, 0.5*labHeight );
   lab_log  = new G4LogicalVolume(lab_box, lab_mat, "lab_log");
   lab_phys = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), "lab_phys", lab_log, world_phys, false,0);

   G4VisAttributes* lab_vat= new G4VisAttributes(blue);
   lab_vat->SetVisibility(true);
   lab_log->SetVisAttributes(lab_vat);

   // Include the STL file here:   ************************************************
   
   auto mesh = CADMesh::TessellatedMesh::FromSTL("Cryo2.stl");
   G4VSolid* cryo_solid = mesh->GetSolid();
   auto cryo_logical = new G4LogicalVolume(cryo_solid, Al, "cryo_logical", 0, 0, 0);   //<---- use your own material (see the list)
   
   auto rotation = new G4RotationMatrix();
   rotation->rotateX(90*deg);

   new G4PVPlacement(rotation, G4ThreeVector(), cryo_logical, "cryo_physical", world_log, false, 0);  //<---- define a hierarchy to attach the volume
   
   //
   

   // include room furniture: **************************************************

   #include "QrocoDetectorRoom.icc"

   // ......................................................................
   // attach user limits ...................................................

   G4cout << G4endl << "User Limits: " << G4endl 
	 << "\t theMaxTimeCuts:     " << G4BestUnit(theMaxTimeCuts,"Time")  
	 << G4endl
	 << "\t theRoomTimeCut:     " << G4BestUnit(theRoomTimeCut,"Time")  
	 << G4endl
	 << "\t theMaxStepSize:     " << G4BestUnit(theMaxStepSize,"Length")
	 << G4endl
	 << "\t theMinEKine:        " << G4BestUnit(theMinEkine,"Energy")   
	 << G4endl
	 << "\t minRoomMinEKine:    " << G4BestUnit(theRoomMinEkine,"Energy")
	 << G4endl << G4endl;

   if (theUserLimitsForRoom != 0) delete theUserLimitsForRoom;
   if (theUserLimitsForDetector != 0) delete theUserLimitsForDetector;

   theUserLimitsForRoom = new G4UserLimits(theMaxStepSize,   // step length max
					  DBL_MAX,          // track length max
					  theRoomTimeCut,   // Time cut
					  theRoomMinEkine); // min energy

   #include "QrocoDetectorRoomLimits.icc"

   theUserLimitsForDetector = new G4UserLimits(theDetectorStepSize,
					   DBL_MAX, // Track Max
					   theMaxTimeCuts,
					   theMinEkine);

   world_log->SetUserLimits(theUserLimitsForRoom);
   lab_log->SetUserLimits(theUserLimitsForRoom);

   return world_phys;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

// specific method to G4UserLimits:= SetUserMinEkine
void QrocoDetectorConstruction::SetRoomEnergyCut(G4double val)
{
   // set minimum charged particle energy cut - NB: for ROOM
   theRoomMinEkine = val;
   if (theUserLimitsForRoom != 0) 
   {
      theUserLimitsForRoom->SetUserMinEkine(val); 
      G4cout << " Changing Room energy cut to: " << G4BestUnit(val,"Energy")
	   << G4endl;
   }
}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

// specific method to G4UserLimits:= SetUserMinEkine
void QrocoDetectorConstruction::SetEnergyCut(G4double val)
{
   // set minimum charged particle energy cut - NB: for Xenon Detector
   theMinEkine = val;
   if (theUserLimitsForDetector != 0) 
   {
      theUserLimitsForDetector->SetUserMinEkine(val);
      G4cout << "Changing Detector energy cut to: " << G4BestUnit(val,"Energy")
	     << G4endl;
   }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

// specific method to G4UserLimits:= SetUserMaxTime
void QrocoDetectorConstruction::SetRoomTimeCut(G4double val)
{
   // set room time cut:
   theRoomTimeCut = val;
   if (theUserLimitsForRoom != 0) 
   {
      theUserLimitsForRoom->SetUserMaxTime(val);
      G4cout << " Changing Room Time cut to: " << G4BestUnit(val,"Time")
	   << G4endl;
   }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

// specific method to G4UserLimits:= SetUserMaxTime
void QrocoDetectorConstruction::SetTimeCut(G4double val)
{
   // set detector time cut:
   theMaxTimeCuts = val;
   if (theUserLimitsForDetector != 0) 
   {
      theUserLimitsForDetector->SetUserMaxTime(val);
      G4cout << " Changing Detector Time cut to: " << G4BestUnit(val,"Time")
	   << G4endl;
   }
}
