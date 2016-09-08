#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include "md.h"

double dnint(double x);

void force_omp(particle *q)
{
    unsigned i, j, k;
    double r2, dx[3], coef, x;
    double **tmp;

/* force initialization */
    for(i=0; i<Npt; i++) for (k=0;k<3;k++) q[i].ff[k] = 0.0;

/* coupled loop for many-body interaction */
#pragma omp parallel default(shared) private(tmp, i, k)
    {
	tmp = malloc(Npt*sizeof **tmp);
	for (i=0;i<Npt;i++) tmp[i] = malloc(3*sizeof *tmp);
	for (i=0;i<Npt;i++) for (k=0;k<3;k++) tmp[i][k] = 0.0;
#pragma omp for private(j,r2,x,dx,coef)
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
			tmp[i][k] += coef * dx[k];
			tmp[j][k] -= coef * dx[k];
		    }
		}
	    }
	}
#pragma omp critical
	{
	    for (i=0;i<Npt;i++) for (k=0;k<3;k++) q[i].ff[k] += tmp[i][k];
	}
	for (i=0;i<Npt;i++) free(tmp[i]);
	free(tmp);
    }
}
  
