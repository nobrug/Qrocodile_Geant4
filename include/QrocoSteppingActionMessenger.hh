#ifndef QrocoSteppingActionMessenger_h
#define QrocoSteppingActionMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

class QrocoSteppingAction;
class G4UIdirectory;
class G4UIcmdWithAString;


class QrocoSteppingActionMessenger: public G4UImessenger {

  public:
    QrocoSteppingActionMessenger(QrocoSteppingAction*);
   ~QrocoSteppingActionMessenger();
    
  void SetNewValue(G4UIcommand*, G4String);

  private:
    QrocoSteppingAction*  steppingAction;   
  
    G4UIcmdWithAString*   colourNeutronCmd;
    G4UIcmdWithAString*   colourGammaCmd;
    G4UIcmdWithAString*   colourOpticalCmd;
    G4UIcmdWithAString*   colourChargedPlusCmd;
    G4UIcmdWithAString*   colourChargedMinusCmd;

};

#endif

