#include <stdio.h>
#include "md.h"

void print_snap(int isnap, particle *q)
{
  unsigned i, k;
  FILE *f;
  char name[256];
  sprintf(name, "snapshot%4.4d.xyz", isnap);
  f = fopen(name,"w");
  fprintf(f, "%d \n", Npt);
  fprintf(f, "#####\n");
  for (i=0; i<Npt; i++) {
    fprintf(f, "C ");
    for (k=0; k<3; k++) {
      fprintf(f, "%f ", q[i].xx[k]);
    }
    fprintf(f, "\n");
  }
  fclose(f);
}
