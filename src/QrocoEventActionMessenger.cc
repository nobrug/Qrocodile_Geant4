#include "QrocoEventActionMessenger.hh"

#include <sstream>

#include "QrocoEventAction.hh"

#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWithABool.hh"
#include "G4UIcommand.hh"
#include "globals.hh"


QrocoEventActionMessenger::QrocoEventActionMessenger(QrocoEventAction* EvAct)
:eventAction(EvAct){

  // saving event information
  dmxDirectory = new G4UIdirectory("/dmx/");
  dmxDirectory->SetGuidance("DM Example commands.");

  SavePmtCmd = new G4UIcmdWithABool("/dmx/savePmt",this);
  SavePmtCmd->SetGuidance("Set flag to save (x,y,z) of hits in PMT");
  SavePmtCmd->SetGuidance("into file 'pmt.out'");
  SavePmtCmd->SetGuidance("Default = false");
  SavePmtCmd->SetParameterName("savePmtFlag", false);

  SaveHitsCmd = new G4UIcmdWithABool("/dmx/saveHits",this);
  SaveHitsCmd->SetGuidance("Set flag to save hits in each run");
  SaveHitsCmd->SetGuidance("into file 'hits.out'");
  SaveHitsCmd->SetGuidance("Default = true");
  SaveHitsCmd->SetParameterName("saveHitsFlag", false);


  // drawing event
  drawDirectory = new G4UIdirectory("/dmx/draw/");
  drawDirectory->SetGuidance("DM Example draw commands.");

  DrawColsCmd = new G4UIcmdWithAString("/dmx/draw/drawColours",this);
  DrawColsCmd->SetGuidance("Tracks drawn by Event (standard colours) or by Step (custom colours)");
  DrawColsCmd->SetGuidance("  Choice : custom, standard(default)");
  DrawColsCmd->SetParameterName("drawColsFlag", false);
  DrawColsCmd->SetCandidates("custom standard");
  DrawColsCmd->AvailableForStates(G4State_Idle);

  DrawTrksCmd = new G4UIcmdWithAString("/dmx/draw/drawTracks",this);
  DrawTrksCmd->SetGuidance("Draw the tracks in the event");
  DrawTrksCmd->SetGuidance("  Choice : none, charged, noscint, all(default)");
  DrawTrksCmd->SetParameterName("drawTrksFlag", false);
  DrawTrksCmd->SetCandidates("none charged noscint all");
  DrawTrksCmd->AvailableForStates(G4State_Idle);

  DrawHitsCmd = new G4UIcmdWithABool("/dmx/draw/drawHits",this);
  DrawHitsCmd->SetGuidance("Set flag to draw hits in PMT.");
  DrawHitsCmd->SetGuidance("Default = true");
  DrawHitsCmd->SetParameterName("drawHitsFlag", false);
  DrawHitsCmd->SetDefaultValue(true);

  PrintCmd = new G4UIcmdWithAnInteger("/dmx/printModulo",this);
  PrintCmd->SetGuidance("Print events modulo n");
  PrintCmd->SetParameterName("EventNb",false);
  PrintCmd->SetRange("EventNb>0");
  PrintCmd->AvailableForStates(G4State_Idle);     

}


QrocoEventActionMessenger::~QrocoEventActionMessenger() {

  delete SavePmtCmd;  
  delete SaveHitsCmd;  
  delete dmxDirectory;
  delete DrawColsCmd;
  delete DrawTrksCmd;
  delete DrawHitsCmd;  
  delete drawDirectory;
  delete PrintCmd;

}

void QrocoEventActionMessenger::SetNewValue
   (G4UIcommand* command, G4String newValue) { 

  if(command == DrawColsCmd)
    eventAction->SetDrawColsFlag(newValue);

  if(command == DrawTrksCmd)
    eventAction->SetDrawTrksFlag(newValue);

  if(command == DrawHitsCmd) {
    G4int vl;
    const char* t = newValue;
    std::istringstream is(t);
    is >> vl;
    eventAction->SetDrawHitsFlag(vl!=0);
  }

  if(command == SavePmtCmd) {
    G4int vl;
    const char* t = newValue;
    std::istringstream is(t);
    is >> vl;
    eventAction->SetSavePmtFlag(vl!=0);
  }

  if(command == SaveHitsCmd) {
    G4int vl;
    const char* t = newValue;
    std::istringstream is(t);
    is >> vl;
    eventAction->SetSaveHitsFlag(vl!=0);
  }

  if(command == PrintCmd)
    {eventAction->SetPrintModulo(PrintCmd->GetNewIntValue(newValue));}


}

