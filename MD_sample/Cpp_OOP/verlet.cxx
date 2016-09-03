#include "md.hxx"

double dnint(double x);

/* First step of velocity verlet */
void MD::vverlet_1(double dt)
{
  unsigned i, k;
  for (i=0; i<Npt; i++) {
    for (k=0; k<3; k++) {
      q[i].xx[k] += dt * q[i].vv[k] + 0.5*dt*dt*q[i].ff[k]/q[i].xm;
      q[i].xx[k] -= box * dnint(q[i].xx[k]/box);
      q[i].vv[i] += 0.5*dt*q[i].ff[k]/q[i].xm;
    }
  }
}

/* Second step of velocity verlet */
void MD::vverlet_2(double dt)
{
  unsigned i, k;
  for (i=0; i<Npt; i++) {
    for (k=0; k<3; k++) {
      q[i].vv[i] += 0.5*dt*q[i].ff[k]/q[i].xm;
    }
  }
}

