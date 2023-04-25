#ifndef QrocoSteppingAction_h
#define QrocoSteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"


class QrocoSteppingActionMessenger;
class QrocoEventAction;
class QrocoAnalysisManager;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class QrocoSteppingAction : public G4UserSteppingAction
{
  public:
    QrocoSteppingAction();
    virtual ~QrocoSteppingAction();

    virtual void UserSteppingAction(const G4Step*);

  public:
    void SetColourNeutronFlag(G4String val)      {colourNeutronFlag     =val;};
    void SetColourGammaFlag(G4String val)        {colourGammaFlag       =val;};
    void SetColourOpticalFlag(G4String val)      {colourOpticalFlag     =val;};
    void SetColourChargedPlusFlag(G4String val)  {colourChargedPlusFlag =val;};
    void SetColourChargedMinusFlag(G4String val) {colourChargedMinusFlag=val;};

  private:
    G4String                    colourNeutronFlag;
    G4String                    colourGammaFlag;
    G4String                    colourOpticalFlag;
    G4String                    colourChargedPlusFlag;
    G4String                    colourChargedMinusFlag;

    QrocoSteppingActionMessenger*  steppingMessenger;

    const QrocoEventAction*  evtAction;  //pointer to event action


};

#endif
