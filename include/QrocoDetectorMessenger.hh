#ifndef QrocoDetectorMessenger_h
#define QrocoDetectorMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

class QrocoDetectorConstruction;
class G4UIdirectory;

class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWithoutParameter;


class QrocoDetectorMessenger: public G4UImessenger {

  public:
    QrocoDetectorMessenger(QrocoDetectorConstruction*);
   ~QrocoDetectorMessenger();
    
  void SetNewValue(G4UIcommand*, G4String);

  private:
    QrocoDetectorConstruction*  detectorConstruction;   
  
    G4UIcmdWithADoubleAndUnit* RoomEKineCutCmd;
    G4UIcmdWithADoubleAndUnit* EKineCutCmd;
    G4UIcmdWithADoubleAndUnit* RoomTimeCutCmd;
    G4UIcmdWithADoubleAndUnit* TimeCutCmd;

};

#endif

