#include <cmath>
#include "md.hxx"

inline double dnint(double x)
{
  double y = (x > 0.0) ? floor(x+0.5): ceil(x-0.5);
  return y;
}

void MD::force()
{
  unsigned i, j, k;
  double r2, dx[3], coef, x;

  /* force initialization */
  for(i=0; i<Npt; i++) for (k=0;k<3;k++) q[i].ff[k] = 0.0;

  /* coupled loop for many-body interaction */
  for (i=0; i<Npt-1; i++) {
    for (j=i+1; j<Npt; j++) {
      r2 = 0.0;
      for (k=0; k<3; k++) {
	x = q[i].xx[k] - q[j].xx[k];
	dx[k] = x - box * dnint(x/box);
	r2 += dx[k]*dx[k];
      }
      if (r2 < rcut2) {
	coef = 1./(r2*sqrt(r2));
	for (k=0; k<3; k++) {
	  q[i].ff[k] += coef * dx[k];
	  q[j].ff[k] -= coef * dx[k];
	}
      }
    }
  }
}
  
