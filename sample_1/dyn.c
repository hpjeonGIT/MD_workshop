#include <stdlib.h>

int main()
{
  double *xx;
  xx = (double *) malloc(sizeof(double)*3);
  xx[0] = xx[1] = xx[2] = 0.0;
  free(xx);
  return 0;
}
