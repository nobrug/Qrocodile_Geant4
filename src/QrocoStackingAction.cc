#include "QrocoStackingAction.hh"

#include "QrocoStackingActionMessenger.hh"
#include "QrocoDetectorConstruction.hh"

#include "G4Track.hh"
#include "G4TrackStatus.hh"
#include "G4VPhysicalVolume.hh"
#include "G4Navigator.hh"
#include "G4TransportationManager.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleTypes.hh"



QrocoStackingAction::QrocoStackingAction() {

  // new messenger
  theMessenger = new QrocoStackingActionMessenger(this);

  // messenger defaults
  killGammasFlag  = 0;

  // global geometry navigator
  gNavigator = G4TransportationManager::GetTransportationManager()
    ->GetNavigatorForTracking();
}


QrocoStackingAction::~QrocoStackingAction() {
  
  delete theMessenger; 
}


G4ClassificationOfNewTrack QrocoStackingAction::ClassifyNewTrack 
(const G4Track* aTrack) {


  static G4int gammasKilled = 0;

  G4ClassificationOfNewTrack classification = fWaiting;

  // Kill gammas from neutrons in concrete wall
  if(killGammasFlag) {
    // check if particle is gamma
    G4ParticleDefinition* particleType = aTrack->GetDefinition();
    if(particleType==G4Gamma::GammaDefinition()) {
      // check if particle is in world_phys
      G4ThreeVector pos = aTrack->GetPosition();
      G4ThreeVector *ptr = NULL;
      G4VPhysicalVolume *theVolume;
      theVolume = gNavigator->LocateGlobalPointAndSetup(pos,ptr,false);
      if(theVolume->GetName() == "world_phys") {
	classification = fKill;
	G4cout << " Total for session Gammas killed in concrete wall (world_phys): "
	       << ++gammasKilled << G4endl;
      }
    }
  }

  return classification;

}


void QrocoStackingAction::NewStage() {;}

    
void QrocoStackingAction::PrepareNewEvent() {;}




