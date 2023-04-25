#ifndef CRYUtils_h
#define CRYUtils_h

#include "CRYParticle.h"
#include <string>

class CRYUtils {
public:

  // Nothing to construct
  CRYUtils();
  ~CRYUtils() {;}

  // Look for and remove trailing spaces from a string
  static std::string removeTrailingSpaces(std::string input);

  // Interface to random number generator
  // (use of external random number generators not yet implmented
  double randomFlat(double min=0., double max=1.);
  static double tmpRandom();
  void setRandomFunction(double (*newFunc)(void)) { rngdptr=newFunc;}

  //Keys for particle types -- enums defined in CRYParticle class
  static std::string partName(CRYParticle::CRYId id);

private:
  double (*rngdptr)(void);

};
#endif
