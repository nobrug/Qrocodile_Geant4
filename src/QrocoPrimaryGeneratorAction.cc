#include <iomanip>
#include "QrocoPrimaryGeneratorAction.hh"

#ifdef QrocoENV_GPS_USE
#include "G4GeneralParticleSource.hh"
#else
#include "QrocoParticleSource.hh"
#endif

#include "QrocoAnalysisManager.hh"

#include "G4Event.hh"

#include "Randomize.hh"

#include "globals.hh"

using namespace std;


QrocoPrimaryGeneratorAction::QrocoPrimaryGeneratorAction() {
  //define particle gun
#ifdef QrocoENV_GPS_USE
  particleGun = new G4GeneralParticleSource();
#else
  particleGun = new QrocoParticleSource();
#endif

  energy_pri=0;
  //  seeds=NULL;
  seeds[0] =-1;
  seeds[1] =-1;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

QrocoPrimaryGeneratorAction::~QrocoPrimaryGeneratorAction() {

  delete particleGun;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void QrocoPrimaryGeneratorAction::InputCRY()
{
	InputState=1;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
void QrocoPrimaryGeneratorAction::UpdateCRY(std::string* MessInput)
{
  CRYSetup *setup=new CRYSetup(*MessInput,"/home/uzh/nobrug/Qrocodile-MC-master/cry_v1.7/data");

  gen = new CRYGenerator(setup);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void QrocoPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) {

  energy_pri = 0.;

  // seeds
  seeds[0] = *G4Random::getTheSeeds();
  seeds[1] = *(G4Random::getTheSeeds()+1);

  particleGun->GeneratePrimaryVertex(anEvent);

  energy_pri = particleGun->GetParticleEnergy();

  //Fill ntuple #1
  G4AnalysisManager* man = G4AnalysisManager::Instance();
  man->FillNtupleDColumn(1,0,energy_pri);
  man->AddNtupleRow(1);
}


