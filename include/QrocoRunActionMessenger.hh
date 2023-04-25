#ifndef QrocoRunActionMessenger_h
#define QrocoRunActionMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

class QrocoRunAction;
class G4UIcmdWithAString;
class G4UIcmdWithABool;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class QrocoRunActionMessenger: public G4UImessenger
{
  public:
    QrocoRunActionMessenger(QrocoRunAction*);
   ~QrocoRunActionMessenger();
    
    void SetNewValue(G4UIcommand*, G4String);
    
  private:
    QrocoRunAction*   QrocoRun;

    G4UIcmdWithAString*   SaveHitsCmd;
    G4UIcmdWithAString*   SavePmtCmd;
    G4UIcmdWithAString*   SaveHistFileCmd;
};

#endif

