#include "QrocoDetectorMessenger.hh"

#include "QrocoDetectorConstruction.hh"

#include "globals.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithoutParameter.hh"

#include "G4RunManager.hh"


QrocoDetectorMessenger::QrocoDetectorMessenger
   (QrocoDetectorConstruction* DC):detectorConstruction(DC) {

  RoomEKineCutCmd = new G4UIcmdWithADoubleAndUnit("/qrocodile/RoomMinEnergyCut",this);
  RoomEKineCutCmd->SetGuidance("Minimum Charged particle cut in ROOM");
  RoomEKineCutCmd->SetParameterName("ECut",false,false);
  RoomEKineCutCmd->SetRange("ECut>=250.0*eV");
  RoomEKineCutCmd->SetDefaultUnit("eV");
  RoomEKineCutCmd->SetUnitCategory("Energy");
  RoomEKineCutCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  EKineCutCmd = new G4UIcmdWithADoubleAndUnit("/qrocodile/MinEnergyCut",this);
  EKineCutCmd->SetGuidance("Minimum Charged particle cut inside detector");
  EKineCutCmd->SetParameterName("ECut",false,false);
  EKineCutCmd->SetRange("ECut>=250.0*eV");
  EKineCutCmd->SetDefaultUnit("eV");
  EKineCutCmd->SetUnitCategory("Energy");
  EKineCutCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  RoomTimeCutCmd = new G4UIcmdWithADoubleAndUnit("/qrocodile/RoomTimeCut",this);
  RoomTimeCutCmd->SetGuidance("Set Time Cut (for neutrons) inside ROOM");
  RoomTimeCutCmd->SetParameterName("RTCut",false,false);
  RoomTimeCutCmd->SetRange("RTCut>0.");
  RoomTimeCutCmd->SetDefaultUnit("ns");
  RoomTimeCutCmd->SetUnitCategory("Time");
  RoomTimeCutCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  TimeCutCmd = new G4UIcmdWithADoubleAndUnit("/qrocodile/TimeCut",this);
  TimeCutCmd->SetGuidance("Set Time Cut (for neutrons) inside detector");
  TimeCutCmd->SetParameterName("TCut",false,false);
  TimeCutCmd->SetRange("TCut>0.");
  TimeCutCmd->SetDefaultUnit("ns");
  TimeCutCmd->SetUnitCategory("Time");
  TimeCutCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

}


//ooooooooooooooooooooooooooooooooooooooooo
QrocoDetectorMessenger::~QrocoDetectorMessenger() 
{
  delete EKineCutCmd;
  delete RoomEKineCutCmd;
  delete RoomTimeCutCmd;
  delete TimeCutCmd;
 }


//ooooooooooooooooooooooooooooooooooooooooo
void QrocoDetectorMessenger::SetNewValue(G4UIcommand* command, 
				       G4String newValue) 
{

  if(command == EKineCutCmd)
   detectorConstruction->
     SetEnergyCut(EKineCutCmd->GetNewDoubleValue(newValue));

  if(command == RoomEKineCutCmd)
   detectorConstruction->
     SetEnergyCut(RoomEKineCutCmd->GetNewDoubleValue(newValue));

  if(command == TimeCutCmd)
   detectorConstruction->
     SetTimeCut(TimeCutCmd->GetNewDoubleValue(newValue));

  if(command == RoomTimeCutCmd)
    detectorConstruction->
      SetRoomTimeCut(RoomTimeCutCmd->GetNewDoubleValue(newValue));

  //trigger a re-optimization of the geometry
  G4RunManager::GetRunManager()->PhysicsHasBeenModified();
  G4RunManager::GetRunManager()->GeometryHasBeenModified();
}