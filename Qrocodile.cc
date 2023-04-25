#include "G4Types.hh"

#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif

#include "G4UImanager.hh"
#include "Randomize.hh"

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "QrocoAnalysisManager.hh"
#include "QrocoDetectorConstruction.hh"
#include "QrocoPhysicsList.hh"
#include "QrocoActionInitializer.hh"

int main(int argc,char** argv) {

  // choose the Random engine
  G4Random::setTheEngine(new CLHEP::RanecuEngine);

  // Construct the default run manager
#ifdef G4MULTITHREADED
  G4MTRunManager* runManager = new G4MTRunManager;
  //runManager->SetNumberOfThreads(2);
#else
  G4RunManager* runManager = new G4RunManager;
#endif

  // set mandatory initialization classes
  runManager->SetUserInitialization(new QrocoDetectorConstruction);
  runManager->SetUserInitialization(new QrocoPhysicsList);
  runManager->SetUserInitialization(new QrocoActionInitializer());

  // visualization manager
  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();

#ifdef QrocoENV_GPS_USE
  G4cout << " Using GPS and not Qroco gun " << G4endl;
#else
  G4cout << " Using the Qroco gun " << G4endl;
#endif


  //Initialize G4 kernel
  runManager->Initialize();

  // get the pointer to the User Interface manager
  G4UImanager* UImanager = G4UImanager::GetUIpointer();

  // Define UI session for interactive mode.
  if(argc == 1)
    {
      G4UIExecutive* ui = new G4UIExecutive(argc, argv);
      UImanager->ApplyCommand("/control/execute initInter.mac");
      ui->SessionStart();
      delete ui;
    }
  // Batch mode
  else
    {
      G4String command = "/control/execute ";
      G4String fileName = argv[1];
      UImanager->ApplyCommand(command+fileName);
    }

  //Close-out analysis:
  // Save histograms
  G4AnalysisManager* man = G4AnalysisManager::Instance();
  man->Write();
  man->CloseFile();
  // Complete clean-up
  delete G4AnalysisManager::Instance();

  if(visManager) delete visManager;

  delete runManager;

  return 0;
}

