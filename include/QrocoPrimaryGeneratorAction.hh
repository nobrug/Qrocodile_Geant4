#ifndef QrocoPrimaryGeneratorMessenger_h
#define QrocoPrimaryGeneratorMessenger_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"
#include "CRYSetup.h"
#include "CRYGenerator.h"
#include "CRYParticle.h"
#include "CRYUtils.h"
#include "vector"
#include "G4ParticleDefinition.hh"

#ifdef QrocoENV_GPS_USE
class G4GeneralParticleSource;
#else
class QrocoParticleSource;
#endif
class QrocoAnalysisManager;

class G4Event;

class QrocoPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {

   public:
      QrocoPrimaryGeneratorAction();
      ~QrocoPrimaryGeneratorAction();
  
   public:
      void GeneratePrimaries(G4Event* anEvent);
      void InputCRY();
      void UpdateCRY(std::string* MessInput);
      void CRYFromFile(G4String newValue);

   private:
#ifdef QrocoENV_GPS_USE
  G4GeneralParticleSource* particleGun;
#else
  std::vector<CRYParticle*> *vect; // vector of generated particles
  QrocoParticleSource* particleGun;
  G4ParticleTable* particleTable;
  CRYGenerator* gen;
  G4int InputState;
#endif

   private:
  //      const long* seeds;
  long seeds[2];
  G4double energy_pri;

   public:
  const long* GetEventSeeds() const       {return seeds;};
  G4double GetEnergyPrimary() const  {return energy_pri;};


};

#endif

