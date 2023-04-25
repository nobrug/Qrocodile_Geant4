#include "QrocoPmtSD.hh"

#include "QrocoDetectorConstruction.hh"

#include "G4VPhysicalVolume.hh"
#include "G4Step.hh"
#include "G4VTouchable.hh"
#include "G4TouchableHistory.hh"
#include "G4SDManager.hh"
#include "G4UImanager.hh"
#include "G4ios.hh"


QrocoPmtSD::QrocoPmtSD(G4String name) 
  :G4VSensitiveDetector(name) {

  G4String HCname="pmtCollection";
  collectionName.insert(HCname);
}


QrocoPmtSD::~QrocoPmtSD() {;}


////////////////////////////////////////////////////////////////////////////
void QrocoPmtSD::Initialize(G4HCofThisEvent*) {

  pmtCollection = new QrocoPmtHitsCollection
    (SensitiveDetectorName,collectionName[0]); 

  HitID = -1;


}



////////////////////////////////////////////////////////////////////////////
G4bool QrocoPmtSD::ProcessHits
  (G4Step* aStep, G4TouchableHistory*){

  // make known hit position
  QrocoPmtHit* aPmtHit = new QrocoPmtHit();
  aPmtHit->SetPos(aStep->GetPostStepPoint()->GetPosition());
  aPmtHit->SetTime(aStep->GetPostStepPoint()->GetGlobalTime());
  HitID = pmtCollection->insert(aPmtHit);

  return true;
 
}



////////////////////////////////////////////////////////////////////////////
void QrocoPmtSD::EndOfEvent(G4HCofThisEvent* HCE) {

  G4String HCname = collectionName[0];

  static G4int HCID = -1;
  if(HCID<0)
    HCID = G4SDManager::GetSDMpointer()->GetCollectionID(HCname);
  HCE->AddHitsCollection(HCID,pmtCollection);
  
  G4int nHits = pmtCollection->entries();
  if (verboseLevel>=1) {
    G4cout << "     PMT collection: " << nHits << " hits" << G4endl;
    if (verboseLevel>=2)
      pmtCollection->PrintAllHits();
  }


}


////////////////////////////////////////////////////////////////////////////
void QrocoPmtSD::clear()    {;}


void QrocoPmtSD::DrawAll()  {;}


void QrocoPmtSD::PrintAll() {;}




