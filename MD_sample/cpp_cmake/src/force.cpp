#include <cmath>
#include "md.h"

void MD::force()
{
  double r2, dxx, dxy, dxz, coef;

  // force initialization 
  for(std::size_t i=0; i<Npt; i++) {
      q.fx[i] = 0.0;
      q.fy[i] = 0.0;
      q.fz[i] = 0.0;
  }

  // coupled loop for many-body interaction
  for (std::size_t i=0; i<Npt-1; i++) {
      for (std::size_t j=i+1; j<Npt; j++) {
	  dxx = q.xx[i] - q.xx[j];
	  dxx -= box * dnint(dxx/box);
	  dxy = q.xy[i] - q.xy[j];
	  dxy -= box * dnint(dxy/box);
	  dxz = q.xz[i] - q.xz[j];
	  dxz -= box * dnint(dxz/box);
	  r2 = dxx*dxx + dxy*dxy + dxz*dxz;
	  if (r2 < rcut2) {
	      coef = 1./(r2*sqrt(r2));
	      q.fx[i] += coef * dxx;
	      q.fy[i] += coef * dxy;
	      q.fz[i] += coef * dxz;
	      q.fx[j] -= coef * dxx;
	      q.fy[j] -= coef * dxy;
	      q.fz[j] -= coef * dxz;
	  }
      }
  }
}

