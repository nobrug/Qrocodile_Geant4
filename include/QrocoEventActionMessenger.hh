#ifndef QrocoEventActionMessenger_h
#define QrocoEventActionMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

class QrocoEventAction;
class G4UIdirectory;
class G4UIcmdWithAString;
class G4UIcmdWithAnInteger;
class G4UIcmdWithABool;


class QrocoEventActionMessenger: public G4UImessenger {

  public:
    QrocoEventActionMessenger(QrocoEventAction*);
   ~QrocoEventActionMessenger();
    
  void SetNewValue(G4UIcommand*, G4String);
    
  private:
    QrocoEventAction*     eventAction;   
  
    G4UIdirectory*        dmxDirectory;
    G4UIdirectory*        drawDirectory;
    G4UIcmdWithAString*   DrawTrksCmd;
    G4UIcmdWithAString*   DrawColsCmd;
    G4UIcmdWithABool*     DrawHitsCmd;    
    G4UIcmdWithABool*     SavePmtCmd;    
    G4UIcmdWithABool*     SaveHitsCmd;    
    G4UIcmdWithAnInteger* PrintCmd;    

};

#endif
