#include <cmath>
#include "md.h"


void force(particle *q)
{
  int i, j, k;
  double r2, dx[3], force_term;

  for(i=0;i<N;i++) for(k=0;k<3;k++) q[i].f[k] = 0.0;

  for (i=0;i<N-1;i++) {
    for (j=i+1;j<N;j++) {
      r2 = 0.0;
      for (k=0;k<3;k++) {
	dx[k] = q[i].x[k] - q[j].x[k];
        r2 += dx[k]*dx[k];
      }
      force_term = 1./pow(r2, 1.5);
      
      for (k=0;k<3;k++) {
        q[i].f[k] += force_term*dx[k];
        q[j].f[k] -= force_term*dx[k];
      }
    }
  }
}

