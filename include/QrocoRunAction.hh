#ifndef QrocoRunAction_h
#define QrocoRunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class QrocoRunActionMessenger;
class G4Run;
class QrocoAnalysisManager;

class QrocoRunAction : public G4UserRunAction
{
  public:
    QrocoRunAction();
   ~QrocoRunAction();

  public:
    void BeginOfRunAction(const G4Run*);
    void EndOfRunAction(const G4Run*);

  public:
    void SetsavehitsFile   (G4String val)        { savehitsFile   = val;};
    void SetsavepmtFile    (G4String val)        { savepmtFile    = val;};
    void SetsavehistFile   (G4String val)        { savehistFile   = val;};

    G4String GetsavehitsFile()  const     {return savehitsFile;};
    G4String GetsavepmtFile()  const      {return savepmtFile;};

  private:
    void Book();

  //messenger
    G4String savehitsFile;
    G4String savepmtFile;
    G4String savehistFile;

  QrocoRunActionMessenger* runMessenger;

};

#endif

