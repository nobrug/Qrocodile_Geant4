#include "QrocoPmtHit.hh"

#include "G4UnitsTable.hh"
#include "G4VVisManager.hh"
#include "G4Circle.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"

#include <iomanip>

G4ThreadLocal G4Allocator<QrocoPmtHit> *QrocoPmtHitsAllocator;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

QrocoPmtHit::QrocoPmtHit() {
  
  pos = G4ThreeVector(0., 0., 0.);
  time=0.;

}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

QrocoPmtHit::~QrocoPmtHit() {;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

QrocoPmtHit::QrocoPmtHit(const QrocoPmtHit& right) : G4VHit(right) {

  pos  = right.pos;
  time = right.time;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

const QrocoPmtHit& QrocoPmtHit::operator=(const QrocoPmtHit& right) {

  pos  = right.pos;
  time = right.time;

  return *this;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

G4bool QrocoPmtHit::operator==(const QrocoPmtHit& right) const {

  return (this==&right) ? true : false;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void QrocoPmtHit::Draw()  {

  G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();

  if(pVVisManager) {
    G4Circle circle(pos);
    circle.SetScreenSize(0.002);
    circle.SetFillStyle(G4Circle::filled);
    G4Colour colour(1.,1.,0.);
    G4VisAttributes attribs(colour);
    circle.SetVisAttributes(attribs);
    pVVisManager->Draw(circle);
  }


}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void QrocoPmtHit::Print() {

  //  G4cout << "      PMT hit: " << G4BestUnit(pos,"Length") << G4endl;

  G4cout << "      PMT hit: " << std::setw(5) << G4BestUnit(time,"Time") 
	 << ", at " << G4BestUnit(pos,"Length") << G4endl;


}



