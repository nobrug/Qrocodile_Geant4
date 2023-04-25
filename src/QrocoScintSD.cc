#include "QrocoScintSD.hh"

#include "QrocoScintHit.hh"
#include "QrocoDetectorConstruction.hh"

#include "G4VPhysicalVolume.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4SDManager.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleTypes.hh"
#include "G4Ions.hh"
#include "G4ios.hh"

#include "G4OpticalPhoton.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

QrocoScintSD::QrocoScintSD(G4String name) 
  :G4VSensitiveDetector(name)
{
  G4String HCname="scintillatorCollection";
  collectionName.insert(HCname);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

QrocoScintSD::~QrocoScintSD(){ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void QrocoScintSD::Initialize(G4HCofThisEvent*)
{
  scintillatorCollection = new QrocoScintHitsCollection
    (SensitiveDetectorName,collectionName[0]);

  HitID = -1;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

G4bool QrocoScintSD::ProcessHits(G4Step* aStep, G4TouchableHistory*)
{

  //need to know if this is an optical photon and exclude it:
  if(aStep->GetTrack()->GetDefinition()
     == G4OpticalPhoton::OpticalPhotonDefinition()) return false;

  
  G4double edep = aStep->GetTotalEnergyDeposit();
  G4ParticleDefinition* particleType = aStep->GetTrack()->GetDefinition();
  G4String particleName = particleType->GetParticleName();

  G4double stepl = 0.;
  if (particleType->GetPDGCharge() != 0.)
    stepl = aStep->GetStepLength();
  
  if ((edep==0.)&&(stepl==0.)) return false;      


  // fill in hit
  QrocoScintHit* newHit = new QrocoScintHit();
  newHit->SetEdep(edep);
  newHit->SetPos(aStep->GetPostStepPoint()->GetPosition());
  newHit->SetTime(aStep->GetPreStepPoint()->GetGlobalTime());
  newHit->SetParticle(particleName);
  newHit->SetParticleEnergy(aStep->GetPreStepPoint()->GetKineticEnergy() );

  HitID = scintillatorCollection->insert(newHit);
  
  return true;
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void QrocoScintSD::EndOfEvent(G4HCofThisEvent* HCE)
{

  G4String HCname = collectionName[0];
  static G4int HCID = -1;
  if(HCID<0)
    HCID = G4SDManager::GetSDMpointer()->GetCollectionID(HCname);
  HCE->AddHitsCollection(HCID,scintillatorCollection);

  G4int nHits = scintillatorCollection->entries();
  if (verboseLevel>=1)
    G4cout << "     LXe collection: " <<  nHits << " hits" << G4endl;
  if (verboseLevel>=2)
    scintillatorCollection->PrintAllHits();

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void QrocoScintSD::clear()
{} 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void QrocoScintSD::DrawAll()
{} 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void QrocoScintSD::PrintAll()
{} 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

