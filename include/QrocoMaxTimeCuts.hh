#ifndef QrocoMaxTimeCuts_h
#define QrocoMaxTimeCuts_h 1

#include "G4ios.hh"
#include "globals.hh"
#include "QrocoSpecialCuts.hh"


class QrocoMaxTimeCuts : public QrocoSpecialCuts
{
  public:     

     QrocoMaxTimeCuts(const G4String& processName ="QrocoMaxTimeCuts" );

     virtual ~QrocoMaxTimeCuts();

     // PostStep GPIL
     virtual G4double PostStepGetPhysicalInteractionLength(
                             const G4Track& track,
			     G4double   previousStepSize,
			     G4ForceCondition* condition
			    );
            
			    
  private:
  
  // hide assignment operator as private 
      QrocoMaxTimeCuts(QrocoMaxTimeCuts&);
      QrocoMaxTimeCuts& operator=(const QrocoMaxTimeCuts& right);

};

#endif

