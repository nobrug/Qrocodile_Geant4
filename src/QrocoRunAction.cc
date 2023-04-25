#include "QrocoRunActionMessenger.hh"
#include "QrocoRunAction.hh"

#include "G4Run.hh"
#include "G4ios.hh"

#include <fstream>

#include "QrocoAnalysisManager.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

QrocoRunAction::QrocoRunAction()
{
  runMessenger = new QrocoRunActionMessenger(this);
  savehitsFile = "hits.out";
  savepmtFile  = "pmt.out";
  savehistFile = "dmx";
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

QrocoRunAction::~QrocoRunAction()
{
  delete runMessenger;
  runMessenger = 0;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void QrocoRunAction::BeginOfRunAction(const G4Run* aRun)
{
  //Master mode or sequential
  if (IsMaster())    
    G4cout << "### Run " << aRun->GetRunID() << " starts (master)." << G4endl;
  else
    G4cout << "### Run " << aRun->GetRunID() << " starts (worker)." << G4endl;
  
  // Book histograms and ntuples
  Book();

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void QrocoRunAction::EndOfRunAction(const G4Run*)
{;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void QrocoRunAction::Book()
{  
  // Get/create analysis manager
  G4AnalysisManager* man = G4AnalysisManager::Instance();
  
  // Open an output file
  man->OpenFile(savehistFile);
  man->SetFirstHistoId(1);
  man->SetFirstNtupleId(1);


  // ---- primary ntuple ------
  // id==1
  man->CreateNtuple("tree1", "Particle Source Energy");
  man->CreateNtupleDColumn("energy");
  man->FinishNtuple();

  // ---- secondary ntuple ------   
  //id==2
  man->CreateNtuple("tree2", "Scintillation Hits Info");
  man->CreateNtupleDColumn("Event");
  man->CreateNtupleDColumn("e_prim");
  man->CreateNtupleDColumn("tot_e");
  man->CreateNtupleDColumn("s_hits");
  man->CreateNtupleDColumn("xe_time");
  man->CreateNtupleDColumn("num_ph");
  man->CreateNtupleDColumn("avphtime");
  man->CreateNtupleDColumn("firstpart");
  man->CreateNtupleDColumn("firstparte");
  man->CreateNtupleDColumn("gamma");
  man->CreateNtupleDColumn("neutron");
  man->CreateNtupleDColumn("posi");
  man->CreateNtupleDColumn("elec");
  man->CreateNtupleDColumn("other");
  man->CreateNtupleDColumn("seed1");
  man->CreateNtupleDColumn("seed2");
  man->FinishNtuple();

  // ---- tertiary ntuple ------   
  //id==3
  man->CreateNtuple("tree3", "PMT Hits Info");
  man->CreateNtupleDColumn("event");
  man->CreateNtupleDColumn("hits");
  man->CreateNtupleDColumn("xpos");
  man->CreateNtupleDColumn("ypos");
  man->CreateNtupleDColumn("zpos");
  man->FinishNtuple();
 
  // Creating 1-dimensional histograms
  man->CreateH1("h1","Source Energy /keV",  1000,0.,10000.);
  man->CreateH1("h2","Energy Deposit /keV", 1000,0.,1000.);
  man->CreateH1("h3","Nuclear Recoil Edep /keV", 100,0.,100.);
  man->CreateH1("h4","Number of Photons - LowE", 200,0.,200.);
  man->CreateH1("h5","Number of Photons - HighE", 100,0.,10000.);
  man->CreateH1("h6","Average Photon Arrival/ns", 200,0.,200.);
  man->CreateH1("h7","1st event Photon Arrival", 200,0.,200.);
  man->CreateH1("h8","Gamma Energy Deposit/keV", 1000,0.,1000.);
  man->CreateH1("h9","Neutron Ener Deposit/keV", 1000,0.,1000.);
  man->CreateH1("h10","Electron Ener Deposit/keV",1000,0.,1000.);
  man->CreateH1("h11","Positron Ener Deposit/keV",1000,0.,1000.);
  man->CreateH1("h12","Other Ener Deposit/keV", 1000,0.,1000.);

  //Creating 2-dimensional histograms
  man->CreateH2("hh1","PMT Hit Pattern", 
		300 ,-30.,30.,300,-30.,30.);
  man->CreateH2("hh2","1st event PMT Hit Pattern", 
		300 ,-30.,30.,300,-30.,30.);

  return;

}


