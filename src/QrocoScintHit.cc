#include "QrocoScintHit.hh"
#include "G4UnitsTable.hh"
#include "G4VVisManager.hh"
#include "G4Circle.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"
#include <iomanip>

G4ThreadLocal G4Allocator<QrocoScintHit> *QrocoScintHitAllocator;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

QrocoScintHit::QrocoScintHit()
{
  edep=0.;
  pos = G4ThreeVector(0., 0., 0.);
  time = 0.;
  particleEnergy = 0.;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

QrocoScintHit::~QrocoScintHit()
{;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

QrocoScintHit::QrocoScintHit(const QrocoScintHit& right)
  : G4VHit(right)
{
  edep      = right.edep;
  pos       = right.pos;
  time           = right.time;
  particleName   = right.particleName;
  particleEnergy = right.particleEnergy;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

const QrocoScintHit& QrocoScintHit::operator=(const QrocoScintHit& right)
{
  edep      = right.edep;
  pos       = right.pos;
  time            = right.time;
  particleName    = right.particleName;
  particleEnergy  = right.particleEnergy;
  return *this;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

G4bool QrocoScintHit::operator==(const QrocoScintHit& right) const
{
  return (this==&right) ? true : false;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
void QrocoScintHit::Draw()
{;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void QrocoScintHit::Print()
{

  G4cout << "      LXe hit ENERGY: " << std::setw(5) << G4BestUnit(edep,"Energy") 
	 << ", at " << G4BestUnit(pos,"Length") << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....


