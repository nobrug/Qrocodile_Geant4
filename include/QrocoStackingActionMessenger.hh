#ifndef QrocoStackingActionMessenger_h
#define QrocoStackingActionMessenger_h 1

#include "G4UImessenger.hh"
#include "globals.hh"

class QrocoStackingAction;
class G4UIcmdWithABool;


class QrocoStackingActionMessenger: public G4UImessenger {

  public:
    QrocoStackingActionMessenger(QrocoStackingAction*);
    ~QrocoStackingActionMessenger();
    
  public:
    void SetNewValue(G4UIcommand* , G4String);

  private:
    QrocoStackingAction* QrocoAction;

  private:
    G4UIcmdWithABool* KillGammasCmd;
    
};

#endif

