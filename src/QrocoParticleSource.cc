#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#include "QrocoParticleSource.hh"
#include "QrocoPrimaryGeneratorAction.hh"

#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"
#include "G4PrimaryParticle.hh"
#include "G4Event.hh"
#include "Randomize.hh"
#include "G4TransportationManager.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4IonTable.hh"
#include "G4Ions.hh"
#include "G4TrackingManager.hh"
#include "G4Track.hh"

#include "CRYSetup.h"
#include "CRYParticle.h"
#include "CRYUtils.h"


QrocoParticleSource::QrocoParticleSource() {

  NumberOfParticlesToBeGenerated = 1;
  particle_definition = NULL;
  G4ThreeVector zero(0., 0., 0.);
  particle_momentum_direction = G4ParticleMomentum(1., 0., 0.);
  particle_energy = 1.0*MeV;
  particle_position = zero;
  particle_time = 0.0;
  particle_polarization = zero;
  particle_charge = 0.0;

  SourcePosType = "Volume";
  Shape = "NULL";
  halfz = 0.;
  Radius = 0.;
  CentreCoords = zero;
  Confine = false;
  VolName = "NULL";

  AngDistType = "iso"; 
  MinTheta = 0.;
  MaxTheta = pi;
  MinPhi = 0.;
  MaxPhi = twopi;

  EnergyDisType = "Mono";
  MonoEnergy = 1*MeV;

  verbosityLevel = 0;
  
  //cryInputFile = "input.cry";
  theMessenger = new QrocoParticleSourceMessenger(this);
  gNavigator = G4TransportationManager::GetTransportationManager()
    ->GetNavigatorForTracking();
    
  CRYSetup *crySetup = new CRYSetup("/home/uzh/nobrug/Qrocodile-MC-master/cry_v1.7/geant/setup.file", "/home/uzh/nobrug/Qrocodile-MC-master/cry_v1.7/data");
    cry_generator = new CRYGenerator(crySetup);
    cry_particle = new CRYParticle(CRYParticle::Gamma,0,1.0);
    auto vector = new std::vector<CRYParticle*>;    //Create vector to store the CRY particle properties
    G4ParticleTable *particleTable =  G4ParticleTable::GetParticleTable(); // Create the table containing all particle names

}

QrocoParticleSource::~QrocoParticleSource()
{
  delete theMessenger;
  delete cry_generator;
  delete cry_particle;
}




void QrocoParticleSource::SetPosDisType(G4String PosType) 
{
  SourcePosType = PosType;
}

void QrocoParticleSource::SetPosDisShape(G4String shapeType)
{
  Shape = shapeType;
}

void QrocoParticleSource::SetCentreCoords(G4ThreeVector coordsOfCentre)
{
  CentreCoords = coordsOfCentre;
}

void QrocoParticleSource::SetHalfZ(G4double zhalf)
{
  halfz = zhalf;
}

void QrocoParticleSource::SetRadius(G4double radius)
{
  Radius = radius;
}

void QrocoParticleSource::ConfineSourceToVolume(G4String Vname)
{
  VolName = Vname;
  if(verbosityLevel == 2) G4cout << VolName << G4endl;

  // checks if selected volume exists
  G4VPhysicalVolume *tempPV      = NULL;
  G4PhysicalVolumeStore *PVStore = 0;
  G4String theRequiredVolumeName = VolName;
  PVStore = G4PhysicalVolumeStore::GetInstance();
  G4int i = 0;
  G4bool found = false;
  if(verbosityLevel == 2) G4cout << PVStore->size() << G4endl;

  // recasting required since PVStore->size() is actually a signed int...
  while (!found && i<(G4int)PVStore->size())
    {
      tempPV = (*PVStore)[i];
      found  = tempPV->GetName() == theRequiredVolumeName;
      if(verbosityLevel == 2)
	G4cout << i << " " << " " << tempPV->GetName() 
	       << " " << theRequiredVolumeName << " " << found << G4endl;
      if (!found)
	{i++;}
    }

  // found = true then the volume exists else it doesnt.
  if(found == true) {
    if(verbosityLevel >= 1)
      G4cout << "Volume " << VolName << " exists" << G4endl;
    Confine = true;
  }
  else if(VolName=="NULL")
    Confine = false;
  else {
    G4cout << " **** Error: Volume does not exist **** " << G4endl;
    G4cout << " Ignoring confine condition" << G4endl;
    VolName = "NULL";
    Confine = false;
  }

}


void QrocoParticleSource::SetAngDistType(G4String atype)
{
  AngDistType = atype;
}


void QrocoParticleSource::GeneratePointSource()
{
  // Generates Points given the point source.
  if(SourcePosType == "Point")
    particle_position = CentreCoords;
  else
    if(verbosityLevel >= 1)
      G4cout << "Error SourcePosType is not set to Point" << G4endl;
}


void QrocoParticleSource::GeneratePointsInVolume()
{
  G4ThreeVector RandPos;
  G4double x=0., y=0., z=0.;
  
  if(SourcePosType != "Volume" && verbosityLevel >= 1)
    G4cout << "Error SourcePosType not Volume" << G4endl;
  
  if(Shape == "Sphere") {
    x = Radius*2.;
    y = Radius*2.;
    z = Radius*2.;
    while(((x*x)+(y*y)+(z*z)) > (Radius*Radius)) {
      x = G4UniformRand();
      y = G4UniformRand();
      z = G4UniformRand();
      
      x = (x*2.*Radius) - Radius;
      y = (y*2.*Radius) - Radius;
      z = (z*2.*Radius) - Radius;
    }
  }

  else if(Shape == "Cylinder") {
    x = Radius*2.;
    y = Radius*2.;
    while(((x*x)+(y*y)) > (Radius*Radius)) {
      x = G4UniformRand();
      y = G4UniformRand();
      z = G4UniformRand();
      x = (x*2.*Radius) - Radius;
      y = (y*2.*Radius) - Radius;
      z = (z*2.*halfz) - halfz;
    }
  }
  
  else
    G4cout << "Error: Volume Shape Does Not Exist" << G4endl;

  RandPos.setX(x);
  RandPos.setY(y);
  RandPos.setZ(z);
  particle_position = CentreCoords + RandPos;

}


G4bool QrocoParticleSource::IsSourceConfined()
{

  // Method to check point is within the volume specified
  if(Confine == false)
    G4cout << "Error: Confine is false" << G4endl;
  G4ThreeVector null(0.,0.,0.);
  G4ThreeVector *ptr;
  ptr = &null;

  // Check particle_position is within VolName
  G4VPhysicalVolume *theVolume;
  theVolume=gNavigator->LocateGlobalPointAndSetup(particle_position,ptr,true);
  G4String theVolName = theVolume->GetName();
  if(theVolName == VolName) {
    if(verbosityLevel >= 1)
      G4cout << "Particle is in volume " << VolName << G4endl;
    return(true);
  }
  else
    return(false);
}


void QrocoParticleSource::SetParticleMomentumDirection
   (G4ParticleMomentum aDirection) {

  particle_momentum_direction =  aDirection.unit();
}


void QrocoParticleSource::GenerateIsotropicFlux()
{

  G4double rndm, rndm2;
  G4double px, py, pz;

  G4double sintheta, sinphi, costheta, cosphi;
  rndm = G4UniformRand();
  costheta = std::cos(MinTheta) - rndm * (std::cos(MinTheta) - std::cos(MaxTheta));
  sintheta = std::sqrt(1. - costheta*costheta);
  
  rndm2 = G4UniformRand();
  Phi = MinPhi + (MaxPhi - MinPhi) * rndm2; 
  sinphi = std::sin(Phi);
  cosphi = std::cos(Phi);

  px = -sintheta * cosphi;
  py = -sintheta * sinphi;
  pz = -costheta;

  G4double ResMag = std::sqrt((px*px) + (py*py) + (pz*pz));
  px = px/ResMag;
  py = py/ResMag;
  pz = pz/ResMag;

  particle_momentum_direction.setX(px);
  particle_momentum_direction.setY(py);
  particle_momentum_direction.setZ(pz);

  // particle_momentum_direction now holds unit momentum vector.
  if(verbosityLevel >= 2)
    G4cout << "Generating isotropic vector: " << particle_momentum_direction << G4endl;
}


void QrocoParticleSource::SetEnergyDisType(G4String DisType)
{
  EnergyDisType = DisType;
}

void QrocoParticleSource::SetMonoEnergy(G4double menergy)
{
  MonoEnergy = menergy;
}

void QrocoParticleSource::GenerateMonoEnergetic()
{
  particle_energy = MonoEnergy;
}


void QrocoParticleSource::SetVerbosity(int vL)
{
  verbosityLevel = vL;
  G4cout << "Verbosity Set to: " << verbosityLevel << G4endl;
}

void QrocoParticleSource::SetParticleDefinition
  (G4ParticleDefinition* aParticleDefinition)
{
  particle_definition = aParticleDefinition;
  particle_charge = particle_definition->GetPDGCharge();
}

void QrocoParticleSource::GenerateCRYPrimaryVertex(G4Event *evt)
{
    cry_generator->genEvent();

    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName = CRYUtils::partName(cry_particle->id());
    G4ParticleDefinition *particleDef = particleTable->FindParticle(particleName);

    G4double energy = cry_particle->ke() * MeV;
    G4ThreeVector position = G4ThreeVector(cry_particle->x() * m, cry_particle->y() * m, cry_particle->z() * m);
    G4double time = cry_particle->t() * second;

    G4ThreeVector momentum = G4ThreeVector(cry_particle->u(), cry_particle->v(), cry_particle->w());
    momentum = momentum.unit() * energy;

    G4PrimaryVertex *vertex = new G4PrimaryVertex(position, time);

    G4PrimaryParticle *particle = new G4PrimaryParticle(particleDef, momentum.x(), momentum.y(), momentum.z());
    particle->SetCharge(particleDef->GetPDGCharge());
    vertex->SetPrimary(particle);

    evt->AddPrimaryVertex(vertex);
}


void QrocoParticleSource::GeneratePrimaryVertex(G4Event *evt)
{
  if (useCRY)
  {
     GenerateCRYPrimaryVertex(evt);
  }
  
  else 
  {
  if(particle_definition==NULL) {
    G4cout << "No particle has been defined!" << G4endl;
    return;
  }
  
  // Position
  G4bool srcconf = false;
  G4int LoopCount = 0;
  
  while(srcconf == false)  {
    if(SourcePosType == "Point")
      GeneratePointSource();
    else if(SourcePosType == "Volume")
      GeneratePointsInVolume();
    else {
      G4cout << "Error: SourcePosType undefined" << G4endl;
      G4cout << "Generating point source" << G4endl;
      GeneratePointSource();
    }
    if(Confine == true) {
      srcconf = IsSourceConfined();
      // if source in confined srcconf = true terminating the loop
      // if source isnt confined srcconf = false and loop continues
    }
    else if(Confine == false)
      srcconf = true; // terminate loop
    
    LoopCount++;
    if(LoopCount == 100000) {
      G4cout << "*************************************" << G4endl;
        G4cout << "LoopCount = 100000" << G4endl;
        G4cout << "Either the source distribution >> confinement" << G4endl;
        G4cout << "or any confining volume may not overlap with" << G4endl;
        G4cout << "the source distribution or any confining volumes" << G4endl;
        G4cout << "may not exist"<< G4endl;
        G4cout << "If you have set confine then this will be ignored" <<G4endl;
        G4cout << "for this event." << G4endl;
        G4cout << "*************************************" << G4endl;
        srcconf = true; //Avoids an infinite loop
      }
  }

  // Angular stuff
  if(AngDistType == "iso")
    GenerateIsotropicFlux();
  else if(AngDistType == "direction")
    SetParticleMomentumDirection(particle_momentum_direction);
  else
    G4cout << "Error: AngDistType has unusual value" << G4endl;
  // Energy stuff
  if(EnergyDisType == "Mono")
    GenerateMonoEnergetic();
  else
    G4cout << "Error: EnergyDisType has unusual value" << G4endl;
  
  // create a new vertex
  G4PrimaryVertex* vertex = 
    new G4PrimaryVertex(particle_position,particle_time);

  if(verbosityLevel >= 2)
    G4cout << "Creating primaries and assigning to vertex" << G4endl;
  // create new primaries and set them to the vertex
  G4double mass =  particle_definition->GetPDGMass();
  G4double energy = particle_energy + mass;
  G4double pmom = std::sqrt(energy*energy-mass*mass);
  G4double px = pmom*particle_momentum_direction.x();
  G4double py = pmom*particle_momentum_direction.y();
  G4double pz = pmom*particle_momentum_direction.z();
  
  if(verbosityLevel >= 1){
    G4cout << "Particle name: " 
	   << particle_definition->GetParticleName() << G4endl; 
    G4cout << "       Energy: "<<particle_energy << G4endl;
    G4cout << "     Position: "<<particle_position<< G4endl; 
    G4cout << "    Direction: "<<particle_momentum_direction << G4endl;
    G4cout << " NumberOfParticlesToBeGenerated: "
	   << NumberOfParticlesToBeGenerated << G4endl;
  }


  for( G4int i=0; i<NumberOfParticlesToBeGenerated; i++ ) {
    G4PrimaryParticle* particle =
      new G4PrimaryParticle(particle_definition,px,py,pz);
    particle->SetMass( mass );
    particle->SetCharge( particle_charge );
    particle->SetPolarization(particle_polarization.x(),
			      particle_polarization.y(),
			      particle_polarization.z());
    vertex->SetPrimary( particle );
  }
  evt->AddPrimaryVertex( vertex );
  if(verbosityLevel > 1)
    G4cout << " Primary Vetex generated "<< G4endl;   
  }
}

void QrocoParticleSource::SetCRYInputFile(G4String newInputFile)
{
    cryInputFile = newInputFile;
    delete cry_generator;
    delete cry_particle;

    CRYSetup *crySetup = new CRYSetup(cryInputFile, "km");
    cry_generator = new CRYGenerator(crySetup);
    cry_particle = new CRYParticle(CRYParticle::Electron,-1,1.0);
}

void QrocoParticleSource::SetUseCRY(G4bool use)
{
    useCRY = use;
}



