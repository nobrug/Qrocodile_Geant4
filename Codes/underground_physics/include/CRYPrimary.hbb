#ifndef CRYPrimary_h
#define CRYPrimary_h

#include <vector>

class CRYUtils;
class CRYData;
class CRYParticle;
class CRYAbsFunction;
class CRYUtils;
class CRYParameter;
class CRYWeightFunc;
class CRYBinning;
class CRYPdf;

class CRYPrimary {

public:
  // data is the data table
  // date is in years to approximate the solar cycle
  // latitude is in degrees!
  CRYPrimary(CRYUtils *utils, CRYData *data, 
	     double date=2007, double latitude=0);

  ~CRYPrimary() {;}

  // Given the parameters specified in the constnructor 
  // and by setWeightFunc (if needed) - a new primary proton
  // is created and returned for further analysis
  CRYParticle *getPrimary();

  // Given the function parameters (but NOT the weights)
  // deterine the rate in the specifed binning
  std::vector<double> partialRates(const std::vector<double> *bins) const;
  std::vector<double> partialRates(const CRYBinning *bins=0) const;

  //either add or recompute weighting from existing function
  void setWeightFunc(double area, CRYWeightFunc *wf=0);

  //The time elapsed during the simulation of primaries 
  double timeSimulated() {return _dt;}

  // Sum of unweighted partial rates
  double totalRate();

private:

  // primary spectrum is a weighted sum of solar min and solar
  // max parmaeters
  CRYAbsFunction *_solarMin;
  CRYAbsFunction *_solarMax;
  CRYParameter* _solarCycleStart;
  CRYParameter* _solarCycleLength;
  double _cycle;

  CRYUtils *_utils; //random numbers

  //Energy boundaries
  double _minEnergy,_maxEnergy;
  CRYBinning *_binning;

  //Optional weighting function
  CRYWeightFunc *_wf;

  //Computed lifetime
  double _lifeTime;

  //Time simulated
  double _dt;

  //Store the maximum of PDF for comparison with randoms
  double _maxPDF;

  //Compute (using weighting function) the maximum pdf value
  void calcMaxPDF();

  CRYPdf *_cachedPdf;
};

#endif
