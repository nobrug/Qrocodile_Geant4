#include "QrocoActionInitializer.hh"
#include "QrocoPrimaryGeneratorAction.hh"
#include "QrocoRunAction.hh"
#include "QrocoEventAction.hh"
#include "QrocoSteppingAction.hh"
#include "QrocoStackingAction.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

QrocoActionInitializer::QrocoActionInitializer() : 
  G4VUserActionInitialization()
{;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void QrocoActionInitializer::Build() const 
{
  SetUserAction(new QrocoPrimaryGeneratorAction());
  SetUserAction(new QrocoRunAction());
  SetUserAction(new QrocoEventAction());
  SetUserAction(new QrocoSteppingAction());
  SetUserAction(new QrocoStackingAction());
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void QrocoActionInitializer::BuildForMaster() const
{
  //Run action in the master
  SetUserAction(new QrocoRunAction());
}