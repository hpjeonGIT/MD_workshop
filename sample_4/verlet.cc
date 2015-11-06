#define xm 10.0
#include <cmath>
#include "md.h"

double dnint(double x);

void verlet_1(particle *q, double dt)
{
  int i, j;
  double x;
  for (i=0;i<N;i++) {
    for (j=0;j<3;j++) {      

      q[i].x[j]  // Fill out
      q[i].v[j]  // Fill out
    }
  }
}

void verlet_2(particle *q, double dt, double &e_kinetic)
{
  int i, j;

  e_kinetic = 0.0;
  for (i=0;i<N;i++) {
    for (j=0;j<3;j++) {
      q[i].v[j] += // Fill out
      e_kinetic += 0.5*xm*q[i].v[j]*q[i].v[j];
    }
  }
}

