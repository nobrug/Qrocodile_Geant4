#ifndef QrocoParticleSource_h
#define QrocoParticleSource_h 1

#include "G4VPrimaryGenerator.hh"
#include "G4Navigator.hh"
#include "G4ParticleMomentum.hh"
#include "G4ParticleDefinition.hh"

#include "QrocoParticleSourceMessenger.hh"

#include "CRYGenerator.h"


class QrocoParticleSource : public G4VPrimaryGenerator {

   public:
     QrocoParticleSource (); 
     ~QrocoParticleSource ();
     void GeneratePrimaryVertex(G4Event *evt);
     
     //Add CRY library
     
     void InitializeCRYGenerator(const std::string& crySetupFile);
     G4bool GenerateCRYParticle();
     
     // Add the SetCRYInputFile method
     void SetCRYInputFile(G4String newInputFile);
     
     // Add the GenerateCRYPrimaryVertex method declaration
     void GenerateCRYPrimaryVertex(G4Event *evt);
     
     // Add the SetUseCRY method
     void SetUseCRY(G4bool use);


   public:

     // position distribution  
     void SetPosDisType(G4String);
     void SetPosDisShape(G4String);
     void SetCentreCoords(G4ThreeVector);
     void SetHalfZ(G4double);
     void SetRadius(G4double);
     void GeneratePointSource();
     void GeneratePointsInVolume();
     G4bool IsSourceConfined();
     void ConfineSourceToVolume(G4String);
  
     // angular distribution
     void SetAngDistType(G4String);
     void SetParticleMomentumDirection(G4ParticleMomentum);
     void GenerateIsotropicFlux();

     // energy distribution 
     void SetEnergyDisType(G4String);
     void SetMonoEnergy(G4double);
     void GenerateMonoEnergetic();
     inline G4double GetParticleEnergy() {return particle_energy;}

     // verbosity
     void SetVerbosity(G4int);
  
     // particle properties
     void SetParticleDefinition(G4ParticleDefinition * aParticleDefinition);
     inline void SetParticleCharge(G4double aCharge)
        { particle_charge = aCharge; }
  
   private:

     // position distribution
     G4String SourcePosType;
     G4String Shape;
     G4double halfz;
     G4double Radius;
     G4ThreeVector CentreCoords;
     G4bool Confine;
     G4String VolName;
     G4String AngDistType;
     G4double MinTheta, MaxTheta, MinPhi, MaxPhi;
     G4double Phi;
     G4String EnergyDisType;
     G4double MonoEnergy;

     // particle properties 
     G4int                  NumberOfParticlesToBeGenerated;
     G4ParticleDefinition*  particle_definition;
     G4ParticleMomentum     particle_momentum_direction;
     G4double               particle_energy;
     G4double               particle_charge;
     G4ThreeVector          particle_position;
     G4double               particle_time;
     G4ThreeVector          particle_polarization;

     // Verbose
     G4int verbosityLevel;

   private:
     
     // Add the cryInputFile declaration
     G4String cryInputFile;
     G4bool useCRY;
     
     //Add CRY Pointer to Generator
     CRYGenerator* cry_generator;
     CRYParticle* cry_particle;
     
     QrocoParticleSourceMessenger *theMessenger;
     G4Navigator *gNavigator;

  
};


#endif

