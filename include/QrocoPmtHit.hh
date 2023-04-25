#ifndef QrocoPmtHit_h
#define QrocoPmtHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"


class QrocoPmtHit : public G4VHit 
{
  public:

      QrocoPmtHit();
     ~QrocoPmtHit();

      QrocoPmtHit(const QrocoPmtHit&);
      const QrocoPmtHit& operator=(const QrocoPmtHit&);
      G4bool operator==(const QrocoPmtHit&) const;

      inline void* operator new(size_t);
      inline void  operator delete(void*);

      void Draw();
      void Print();

  private:
     G4ThreeVector pos;
     G4double time;


  public:
     inline void SetPos(G4ThreeVector xyz)       {pos=xyz;};
     inline G4ThreeVector GetPos()               const {return pos;};

     inline void SetTime(G4double t)             {time=t;};
     inline G4double GetTime()                   const {return time;};


};


// vector collection of one type of hits
typedef G4THitsCollection<QrocoPmtHit> QrocoPmtHitsCollection;


extern G4ThreadLocal G4Allocator<QrocoPmtHit> *QrocoPmtHitsAllocator;


inline void* QrocoPmtHit::operator new(size_t) {
  if (!QrocoPmtHitsAllocator)
    QrocoPmtHitsAllocator = new G4Allocator<QrocoPmtHit>;
  return (void*) QrocoPmtHitsAllocator->MallocSingle();
}


inline void QrocoPmtHit::operator delete(void* aHit) {
  QrocoPmtHitsAllocator->FreeSingle((QrocoPmtHit*) aHit);
}

#endif

