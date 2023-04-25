#ifndef QrocoActionInitializer_h
#define QrocoActionInitializer_h 1

#include "G4VUserActionInitialization.hh"
#include "globals.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class QrocoActionInitializer : public G4VUserActionInitialization
{
public:

  QrocoActionInitializer();
  ~QrocoActionInitializer(){;};
  
  void Build() const;
  void BuildForMaster() const;
  
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

