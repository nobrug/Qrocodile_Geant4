#ifndef QrocoEventAction_h
#define QrocoEventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"
#include "G4ios.hh"

#include "QrocoScintHit.hh"
#include "QrocoPmtHit.hh"

class QrocoRunAction;
class QrocoPrimaryGeneratorAction;
class QrocoEventActionMessenger;
class QrocoAnalysisManager;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
class QrocoEventAction : public G4UserEventAction {

  public:
    QrocoEventAction();
    virtual ~QrocoEventAction();
    virtual void BeginOfEventAction(const G4Event*);
    virtual void EndOfEventAction(const G4Event*);

  private:
    void writeScintHitsToFile();
    void writePmtHitsToFile(const QrocoPmtHitsCollection*);
    void drawTracks(const G4Event*);

  public:
    void SetDrawTrksFlag (G4String val)     {drawTrksFlag    = val;};
    G4String GetDrawTrksFlag() const         {return drawTrksFlag;};

    void SetDrawColsFlag (G4String val)     {drawColsFlag    = val;};
    G4String GetDrawColsFlag() const  {return drawColsFlag;};

    void SetDrawHitsFlag (G4int val)        {drawHitsFlag    = val;};
    void SetSavePmtFlag  (G4int val)        {savePmtFlag     = val;};
    void SetSaveHitsFlag (G4int val)        {saveHitsFlag    = val;};
    void SetPrintModulo  (G4int val)        {printModulo     = val;};

  private:
    G4int event_id;

    const long* seeds;
    G4double energy_pri;

    // hits collections
    G4int scintillatorCollID;                
    G4int pmtCollID;
    G4int S_hits;
    G4int P_hits;

    // event summary
    G4double aveTimePmtHits;
    G4double totEnergy;
    G4double totEnergyGammas;
    G4double totEnergyNeutrons;
    G4double hitEnergy;
    G4double firstLXeHitTime;
    G4double firstParticleE;
    G4double particleEnergy;
    G4String particleName;
    G4String firstParticleName;

    G4bool gamma_ev;
    G4bool neutron_ev;
    G4bool positron_ev;
    G4bool electron_ev;
    G4bool proton_ev;
    G4bool other_ev;
    G4bool start_gamma;
    G4bool start_neutron;

    // messenger
    G4String drawTrksFlag;
    G4String drawColsFlag;
    G4int drawHitsFlag;         
    G4int savePmtFlag;         
    G4int saveHitsFlag;         
    G4int printModulo;                         
    QrocoEventActionMessenger*  eventMessenger;

    const QrocoRunAction*    runAct;  //pointer to run action
    const QrocoPrimaryGeneratorAction* genAction; // pointer to particle generator
  std::ofstream *hitsfile;
  std::ofstream *pmtfile;
};

#endif

