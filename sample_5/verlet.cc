#define xm 10.0
#define alpha 0.1
#include <cmath>
#include "md.h"

double dnint(double x);
double rand_double();

double normal_dist() 
{
  double v1, v2;
  double r = 1.0;
  do {
    v1 = 2.*rand_double() - 1.0;
    v2 = 2.*rand_double() - 1.0;
    r = v1*v1 + v2*v2;
  } while (r >= 1.);
  double x = v1*sqrt(-2.*log(r)/r);
  return x;
}


void verlet_1(particle *q, double dt)
{
  int i, j;
  double x;
  for (i=0;i<N;i++) {
    for (j=0;j<3;j++) {      
      q[i].x[j] =  // Fill out
      q[i].x[j] = q[i].x[j] - l_box*dnint(q[i].x[j]/l_box);
      q[i].v[j] = // Fill out
    }
  }
}

void verlet_2(particle *q, double dt, double &e_kinetic)
{
  int i, j;
  double eta, beta;
  double temperature = T*kb;
  e_kinetic = 0.0;
  beta = sqrt(2.0*alpha*temperature/dt);
  for (i=0;i<N;i++) {
    for (j=0;j<3;j++) {
      eta = normal_dist();
      q[i].f[j] += eta*beta;
      q[i].v[j] = // Fill out
      e_kinetic += 0.5*xm*q[i].v[j]*q[i].v[j];
    }
  }
}

