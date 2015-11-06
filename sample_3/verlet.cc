#define xm 10.0
#include <cmath>
#include "md.h"

void verlet_1(particle *q, double dt)
{
  int i, j;
  double x;
  for (i=0;i<N;i++) {
    for (j=0;j<3;j++) {      
      q[i].x[j] // Fill out
      q[i].v[j] // Fill out
    }
  }
}

void verlet_2(particle *q, double dt)
{
  int i, j;

  for (i=0;i<N;i++) {
    for (j=0;j<3;j++) {
      q[i].v[j] // Fill out
    }
  }
}

