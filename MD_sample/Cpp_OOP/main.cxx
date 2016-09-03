#include <cmath>
#include <algorithm>
#include "md.hxx"

inline double drand()
{
  double x = (double) rand()/ (double) RAND_MAX;
  return x;
}

void MD::data_read()
{
  unsigned i, k;
  for (i=0; i< Npt; i++) {
    for (k=0; k<3; k++) {
      q[i].xx[k] = (drand() - 0.5)*box;
      q[i].vv[k] = 0.0;
      q[i].ff[k] = 0.0;
    }
    q[i].xm = mass;
  }
}

int main(int argc, char *argv[])
{
  unsigned i;
  double dt = 0.1;
  MD *sim;
  sim = new MD;

  sim->data_read();

  do{
    sim->vverlet_1(dt);
    sim->force();
    sim->vverlet_2(dt);
    i++;
    if (i%100 == 0) sim->print_snap(i);
  } while (i < 1000);
  delete sim;
  return 0;
}

