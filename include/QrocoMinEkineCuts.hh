#ifndef QrocoMinEkineCuts_h
#define QrocoMinEkineCuts_h 1

#include "G4ios.hh"
#include "globals.hh"
#include "QrocoSpecialCuts.hh"


class QrocoMinEkineCuts : public QrocoSpecialCuts
{
  public:     

     QrocoMinEkineCuts(const G4String& processName ="QrocoMinEkineCuts" );

     virtual ~QrocoMinEkineCuts();

     // PostStep GPIL
     virtual G4double PostStepGetPhysicalInteractionLength(
                             const G4Track& track,
			     G4double   previousStepSize,
			     G4ForceCondition* condition
			    );
            
			    
  private:
  
  // hide assignment operator as private 
      QrocoMinEkineCuts(QrocoMinEkineCuts&);
      QrocoMinEkineCuts& operator=(const QrocoMinEkineCuts& right);

};

#endif

