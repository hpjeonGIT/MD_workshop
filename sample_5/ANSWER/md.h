#define N 10
#define rcut  9.0
#define l_box  20.0
#define T 300.0          // in Kelvin
#define kb 8.617343E-5   // Boltzmann constant in eV/K
 
typedef struct
{
  double x[3],v[3],f[3];
} particle;

