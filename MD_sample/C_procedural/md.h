#define Npt 1000
#define rcut 9.0
#define rcut2 rcut*rcut
#define box 20.0
#define mass 10.0

typedef struct
{
  double xx[3], vv[3], ff[3], xm;
} particle;
