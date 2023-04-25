#ifndef QrocoStackingAction_H
#define QrocoStackingAction_H 1

#include "globals.hh"
#include "G4UserStackingAction.hh"


class QrocoStackingActionMessenger;
class G4Navigator;
class G4Track;

class QrocoStackingAction : public G4UserStackingAction {

  public:
    QrocoStackingAction();
    virtual ~QrocoStackingAction();

  public:
    virtual G4ClassificationOfNewTrack ClassifyNewTrack(const G4Track* aTrack);
    virtual void NewStage();
    virtual void PrepareNewEvent();

    QrocoStackingActionMessenger* theMessenger;

  private:
    G4bool killGammasFlag;

    G4Navigator* gNavigator; 

  public:
    inline void SetKillGammasFlag(G4bool val)     {killGammasFlag  = val;};

};

#endif