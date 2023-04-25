#include "QrocoStackingActionMessenger.hh"

#include <sstream>

#include "QrocoStackingAction.hh"

#include "G4UIcmdWithABool.hh"
#include "G4UIcommand.hh"
#include "globals.hh"


QrocoStackingActionMessenger::QrocoStackingActionMessenger
  (QrocoStackingAction* msa) :QrocoAction(msa) {

  KillGammasCmd = new G4UIcmdWithABool("/dmx/KillGammasInConcrete",this);
  KillGammasCmd->
    SetGuidance("Kills gammas produced by neutrons in the concrete wall");
  KillGammasCmd->SetGuidance("Default = false");
  KillGammasCmd->SetParameterName("KillGammasFlag", false);
  KillGammasCmd->SetDefaultValue(false);

}

QrocoStackingActionMessenger::~QrocoStackingActionMessenger() {

  delete KillGammasCmd;
}

void QrocoStackingActionMessenger::SetNewValue
   (G4UIcommand* command, G4String newValue) {

  if(command==KillGammasCmd) {
    G4int vl;
    const char* t = newValue;
    std::istringstream is(t);
    is >> vl;
    QrocoAction->SetKillGammasFlag(vl!=0);
  }

}

