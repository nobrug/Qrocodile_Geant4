#ifndef CRYParticle_h
#define CRYParticle_h

#include <string>

class CRYParticle {

public:

  // Known particle types
  // Corresponding names (strings) defined in CRYUtils class 
  enum CRYId { CRYIdMin, Neutron=CRYIdMin, Proton, Pion, Kaon, Muon, Electron, Gamma, CRYIdMax=Gamma};
  
  //Basic constructor
  // ID is particle type (see CRYId enum list)
  // Charge (+1,0,-1)
  // KE is kinetic energy
  //   Units will match units of data tables
  //   Currently MeV
  CRYParticle( CRYId id, int charge, double KE);
  CRYParticle( const CRYParticle &part);

  // Set location of particle 
  //   Units will match units of data tables
  //   Currently m
  void setPosition(double x, double y, double z) { _x=x; _y=y; _z=z;}

  // Set direction of particle 
  void setDirection(double u, double v, double w) { _u=u; _v=v; _w=w;}

  // Set time of particle 
  //   Units will match units of data tables
  //   Currently seconds
  void setTime(double t) {_t=t;}

  //accessors

  //Return all of the defined parameters
  //kinetic energy
  //   Units will match units of data tables
  //   Currently MeV
  double ke() {return _KE;}
  
  //   Location
  //   Units will match units of data tables
  //   Currently m
  double x() {return _x;}
  double y() {return _y;}
  double z() {return _z;}

  //Direction cosines
  double u() {return _u;}
  double v() {return _v;}
  double w() {return _w;}
  int charge() {return _charge;}

  // Time
  //   Units will match units of data tables
  //   Currently seconds
  double t() {return _t;}

  //Particle type
  CRYParticle::CRYId id() {return _id;}

  //Return PDG number (http://pdg.lbl.gov/mc_particle_id_contents.html)
  int PDGid();

  void fill( CRYParticle::CRYId &id, int &q,
         double &ke, double &x, double &y, double &z,
         double &u, double &v, double &w, double &t);

private:
  CRYId _id;
  int _charge;
  double _KE;
  double _u,_v,_w;
  double _x,_y,_z;
  double _t;
};

#endif
