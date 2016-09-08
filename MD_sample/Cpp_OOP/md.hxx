#include <iostream>
const int    Npt  = 100;
const double rcut = 9.0;
const double rcut2= rcut*rcut;
const double box  = 20.0;
const double mass = 10.0;

class Particle {
public:
  double xx[3], vv[3], ff[3], xm;
  Particle(): xm(mass) {
  }
  ~Particle() {
  }
};

class MD {
private:
  Particle *q;
public:
  MD() {
    q = new Particle[Npt];
    std::cout << "MD constructur allocated Particle" << std::endl;
  }
  ~MD() {
    delete[] q;
    std::cout << "MD destructor deallocated Particle" << std::endl;
  }
  void data_read();
  void vverlet_1(double dt);
  void vverlet_2(double dt);
  void force();
  void force_omp();
   void print_snap(int isnap);
};
  
