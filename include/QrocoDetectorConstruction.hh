#ifndef QrocoDetectorConstruction_h
#define QrocoDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "G4Cache.hh"
#include "G4NistManager.hh"

class G4LogicalVolume;
class G4VPhysicalVolume;
class G4Material;

class G4UserLimits;

class QrocoScintSD;
class QrocoPmtSD;

class QrocoDetectorMessenger;

class QrocoDetectorConstruction : public G4VUserDetectorConstruction 
{
public:

  QrocoDetectorConstruction();
  ~QrocoDetectorConstruction();

public:

  G4VPhysicalVolume* Construct();
  void SetRoomEnergyCut(G4double);
  void SetEnergyCut(G4double);
  void SetTimeCut(G4double);
  void SetRoomTimeCut(G4double);
 
private:

  void DefineMaterials();

  G4UserLimits*    theUserLimitsForRoom; 
  G4UserLimits*    theUserLimitsForDetector; 

  G4double         theMaxTimeCuts;
  G4double         theMaxStepSize;
  G4double         theDetectorStepSize;
  G4double         theMinEkine;
  G4double         theRoomMinEkine;
  
  G4double         theRoomTimeCut;


#include "QrocoDetectorMaterial.ihh"  // materials used

  G4LogicalVolume*   world_log;        // pointers
  G4VPhysicalVolume* world_phys;  

#include "QrocoDetectorRoom.ihh"

  G4LogicalVolume*   lab_log;
  G4VPhysicalVolume* lab_phys;  

  // pointer to the Detector Messenger:
  QrocoDetectorMessenger*  detectorMessenger;

};

#endif
