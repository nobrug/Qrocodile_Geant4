#include "QrocoSteppingActionMessenger.hh"

#include "QrocoSteppingAction.hh"
#include "QrocoEventActionMessenger.hh"

#include "globals.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"

QrocoSteppingActionMessenger::QrocoSteppingActionMessenger
   (QrocoSteppingAction* SA):steppingAction(SA) {

  colourNeutronCmd = new G4UIcmdWithAString("/dmx/draw/neutronColour",this);
  colourNeutronCmd->SetGuidance("Colour of neutron in the event");
  colourNeutronCmd->SetGuidance("  Choice : white, grey, lgrey, black, red, green, blue, cyan, magenta(default), yellow, lgreen, lblue");
  colourNeutronCmd->SetParameterName("colourNeutronFlag", false);
  colourNeutronCmd->SetCandidates("white grey lgrey black red green blue cyan magenta yellow lgreen lblue");
  colourNeutronCmd->AvailableForStates(G4State_Idle);

  colourGammaCmd = new G4UIcmdWithAString("/dmx/draw/gammaColour",this);
  colourGammaCmd->SetGuidance("Colour of gamma in the event");
  colourGammaCmd->SetGuidance("  Choice : white, grey, lgrey, black, red, green, blue, cyan(default), magenta, yellow, lgreen, lblue");
  colourGammaCmd->SetParameterName("colourGammaFlag", false);
  colourGammaCmd->SetCandidates("white grey lgrey black red green blue cyan magenta yellow lgreen lblue");
  colourGammaCmd->AvailableForStates(G4State_Idle);

  colourOpticalCmd = new G4UIcmdWithAString("/dmx/draw/opticalColour",this);
  colourOpticalCmd->SetGuidance("Colour of gamma in the event");
  colourOpticalCmd->SetGuidance("  Choice : white(default), grey, lgrey, black, red, green, blue, cyan, magenta, yellow, lgreen, lblue");
  colourOpticalCmd->SetParameterName("colourOpticalFlag", false);
  colourOpticalCmd->SetCandidates("white grey lgrey black red green blue cyan magenta yellow lgreen lblue");
  colourOpticalCmd->AvailableForStates(G4State_Idle);

  colourChargedPlusCmd = new G4UIcmdWithAString("/dmx/draw/chargedplusColour",this);
  colourChargedPlusCmd->SetGuidance("colour of chargedplus in the event");
  colourChargedPlusCmd->SetGuidance("  Choice : white, grey, lgrey, black, red (default), green, blue, cyan, magenta, yellow, lgreen, lblue");
  colourChargedPlusCmd->SetParameterName("ColourChargedPlusFlag", false);
  colourChargedPlusCmd->SetCandidates("white grey lgrey black red(default) green blue cyan magenta yellow lgreen lblue");
  colourChargedPlusCmd->AvailableForStates(G4State_Idle);

  colourChargedMinusCmd = new G4UIcmdWithAString("/dmx/draw/chargedminusColour",this);
  colourChargedMinusCmd->SetGuidance("colour of chargedminus in the event");
  colourChargedMinusCmd->SetGuidance("  Choice : white, grey, lgrey, black, red, green, blue(default), cyan, magenta, yellow, lgreen, lblue");
  colourChargedMinusCmd->SetParameterName("colourChargedMinusFlag", false);
  colourChargedMinusCmd->SetCandidates("white grey lgrey black red green blue cyan magenta yellow lgreen lblue");
  colourChargedMinusCmd->AvailableForStates(G4State_Idle);

}


//ooooooooooooooooooooooooooooooooooooooooo
QrocoSteppingActionMessenger::~QrocoSteppingActionMessenger() {

  delete colourNeutronCmd;  
  delete colourGammaCmd;  
  delete colourOpticalCmd;  
  delete colourChargedPlusCmd;  
  delete colourChargedMinusCmd;  
}


//ooooooooooooooooooooooooooooooooooooooooo
void QrocoSteppingActionMessenger::SetNewValue(G4UIcommand* command, 
  G4String newValue) {

  if(command == colourNeutronCmd)
    steppingAction->SetColourNeutronFlag(newValue);

  if(command == colourGammaCmd)
    steppingAction->SetColourGammaFlag(newValue);

  if(command == colourOpticalCmd)
    steppingAction->SetColourOpticalFlag(newValue);

  if(command == colourChargedPlusCmd)
    steppingAction->SetColourChargedPlusFlag(newValue);

  if(command == colourChargedMinusCmd)
    steppingAction->SetColourChargedMinusFlag(newValue);

}



