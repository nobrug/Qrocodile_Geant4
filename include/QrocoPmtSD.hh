#ifndef QrocoPmtSD_h
#define QrocoPmtSD_h 1

#include "G4VSensitiveDetector.hh"
#include "globals.hh"

#include "QrocoPmtHit.hh"

class G4Step;
class G4HCofThisEvent;

class QrocoPmtSD : public G4VSensitiveDetector {

   public:
  
     QrocoPmtSD(G4String);
     ~QrocoPmtSD();
  
     void Initialize(G4HCofThisEvent*);
     G4bool ProcessHits(G4Step*,G4TouchableHistory*);
     void EndOfEvent(G4HCofThisEvent*);
     void clear();
     void DrawAll();
     void PrintAll();
  
  private:
  
     QrocoPmtHitsCollection* pmtCollection;
     G4int HitID;
};

#endif
