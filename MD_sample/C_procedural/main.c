#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "md.h"

void vverlet_1(particle *q, double dt);
void vverlet_2(particle *q, double dt);
void force    (particle *q);
void print_snap(int isnap, particle *q);

double drand()
{
  double x = (double) rand()/ (double) RAND_MAX;
  return x;
}

void data_read(particle *q)
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
  particle *q;
  q = malloc (Npt * sizeof *q);

  data_read(q);

  do{
    vverlet_1(q, dt);
    force(q);
    vverlet_2(q, dt);
    i++;
    if (i%100 == 0) print_snap(i,q);
  } while (i < 1000);
  free(q);
  return 0;
}

