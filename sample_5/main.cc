#include <iostream>
#include <cmath>
#include <algorithm>
#include "md.h"

void verlet_1(particle *q, double dt);
void verlet_2(particle *q, double dt, double &e_kinetic);
void force   (particle *q, double &e_potential);

double rand_double()
{
  double x = ((double) rand()) / ((double) RAND_MAX);
  return x;
}

void data_read(particle *q)
{
  int i, j;
  for (i=0;i<N;i++) {
    for (j=0;j<3;j++) {
      q[i].x[j] = (rand_double() - 0.5)*l_box;
      q[i].v[j] = 0.0;
      q[i].f[j] = 0.0;
    }
  }

}


int main()
{
  int i=0;
  double dt = 0.1, e_potential, e_kinetic, current_temperature;
  particle *q;
  q = new particle [N];
  
  data_read(q);
  
  do {
    verlet_1(q,dt);
    force(q, e_potential);
    verlet_2(q,dt, e_kinetic);
    current_temperature = 2.0*e_kinetic/3./((double) N)/kb;
    std::cout << i << " " <<  current_temperature << std::endl;
    i++;        
  } while (i<100);
  delete[] q;
  return 0;
}
