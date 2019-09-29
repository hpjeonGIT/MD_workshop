#include <cmath>
#include <algorithm>
#include "md.h"

inline double drand()
{
    double x = static_cast<double> (rand())/ static_cast<double> (RAND_MAX);
  return x;
}

void MD::data_read()
{
    for (std::size_t i=0; i< Npt; i++) {
	std::cout << q.xx[i] << std::endl;
	q.xx[i] = (drand() - 0.5)*box;
	q.xy[i] = (drand() - 0.5)*box;
	q.xz[i] = (drand() - 0.5)*box;
	q.vx[i] = 0.0;
	q.vy[i] = 0.0;
	q.vz[i] = 0.0;
	q.fx[i] = 0.0;
	q.fy[i] = 0.0;
	q.fz[i] = 0.0;
	q.xm[i] = mass;
    }
}

int main(int argc, char** argv)
{
  unsigned i;
  double dt = 0.1;
  MD sim(Npt);

  sim.data_read();

  do{
      sim.vverlet_1(dt);
      sim.force();
      sim.vverlet_2(dt);
      i++;
      if (i%100 == 0) sim.print_snap(i);
  } while (i < 1000);
  return 0;
}

