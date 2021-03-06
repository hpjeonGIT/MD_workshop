#define sigma 4.0
#define epsln 0.007
#include <cmath>
#include "md.h"

double dnint(double x)
{
  double y;
  x > 0.0 ? y = floor(x+0.5): y = ceil(x-0.5);
  return y;
}

void force(particle *q, double &e_potential)
{
  int i, j, k;
  double r2, dx[3], force_term, x, sigma_6, sigma_12;


  e_potential = 0.0;
  for(i=0;i<N;i++) for(k=0;k<3;k++) q[i].f[k] = 0.0;

  for (i=0;i<N-1;i++) {
    for (j=i+1;j<N;j++) {
      r2 = 0.0;
      for (k=0;k<3;k++) {

	dx[k] =  // Fill out
        r2 += dx[k]*dx[k];
      }
      sigma_6 = pow(sigma,6.)/pow(r2,3.);
      sigma_12 = sigma_6*sigma_6;
      e_potential += 4.*epsln*(sigma_12 - sigma_6);
      force_term = // Fill out
      
      for (k=0;k<3;k++) {
        q[i].f[k] += // Fill out
        q[j].f[k] -= // Fill out
      }
    }
  }
}

