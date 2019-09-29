#include <iostream>
#include <vector>
#include <cmath>
const std::size_t  Npt = 100;
const double rcut = 9.0;
const double rcut2= rcut*rcut;
const double box  = 20.0;
const double mass = 10.0;

template <typename T>
inline T dnint(T x)
{
    T y = (x > 0.0) ? floor(x+0.5): ceil(x-0.5);
    return y;
}


class Particle {
public:
    Particle() = default;
    Particle(std::size_t const& npt){
	xm.resize(npt);
	xx.resize(npt);
	xy.resize(npt);
	xz.resize(npt);
	vx.resize(npt);
	vy.resize(npt);
	vz.resize(npt);
	fx.resize(npt);
	fy.resize(npt);
	fz.resize(npt);
	std::cout << "resized as many as " << npt << std::endl;
    }
    std::size_t getSize() {
	return xm.size();
    }
    ~Particle() = default;
    std::vector<double> xm, xx, xy, xz, vx, vy, vz, fx, fy, fz;
};

class MD {
public:
    MD() = default;
MD(std::size_t npt): q(npt) {
	std::cout << "MD constructor allocated Particle" << std::endl;
    }
    ~MD() {
	std::cout << "MD destructor deallocated Particle" << std::endl;
    }
    void data_read();
    void vverlet_1(double const& dt);
    void vverlet_2(double const& dt);
    // (double const dt) works same. Just passing by value. Passing by constant reference might be faster
    void force();
    void print_snap(int const& isnap);
  Particle q;
};


  
