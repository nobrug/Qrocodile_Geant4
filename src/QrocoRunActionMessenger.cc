#include "QrocoRunActionMessenger.hh"

#include <sstream>

#include "QrocoRunAction.hh"

#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithABool.hh"
#include "G4ios.hh"
#include "globals.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

QrocoRunActionMessenger::QrocoRunActionMessenger(QrocoRunAction* run)
:QrocoRun(run)
{ 
  SaveHitsCmd = new G4UIcmdWithAString("/dmx/hitsfile",this);
  SaveHitsCmd->SetGuidance("output file for hits collection (txt)");
  SaveHitsCmd->SetGuidance("Default = hits.out");
  SaveHitsCmd->SetParameterName("savehitsFile", false);
  SaveHitsCmd->SetDefaultValue("hits.out");

  SavePmtCmd = new G4UIcmdWithAString("/dmx/pmtfile",this);
  SavePmtCmd->SetGuidance("output file for pmt hits (txt)");
  SavePmtCmd->SetGuidance("Default = pmt.out");
  SavePmtCmd->SetParameterName("savepmtFile", false);
  SavePmtCmd->SetDefaultValue("pmt.out");

  SaveHistFileCmd = new G4UIcmdWithAString("/dmx/histogramfile",this);
  SaveHistFileCmd->SetGuidance("output file for histograms");
  SaveHistFileCmd->SetGuidance("Default = dmx.his");
  //  SaveHistFileCmd->SetParameterName("savehistFile", false);
  SaveHistFileCmd->SetParameterName("histFile", false);
  SaveHistFileCmd->SetDefaultValue("dmx.his");


  //  FileCmd->AvailableForStates(G4State_Idle);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

QrocoRunActionMessenger::~QrocoRunActionMessenger()
{
  delete SaveHitsCmd;  
  delete SavePmtCmd;  
  delete SaveHistFileCmd;  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void QrocoRunActionMessenger::SetNewValue(G4UIcommand * command,G4String newValue)
{ 
  if(command == SaveHitsCmd)
    QrocoRun->SetsavehitsFile(newValue);

  if(command == SavePmtCmd)
    QrocoRun->SetsavepmtFile(newValue);

  if(command == SaveHistFileCmd)
    QrocoRun->SetsavehistFile(newValue);


}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....





