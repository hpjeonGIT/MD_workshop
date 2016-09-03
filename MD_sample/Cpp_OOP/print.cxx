#include <iostream>
#include <fstream>
#include "md.hxx"

void MD::print_snap(int isnap)
{
  unsigned i, k;
  std::ofstream f;
  char name[256];
  sprintf(name, "snapshot%4.4d.xyz", isnap);
  f.open(name);
  f << Npt << std::endl;
  f << "#######" << std::endl;
  for (i=0; i<Npt; i++) {
    f << "C";
    for (k=0; k<3; k++) {
      f << " " << q[i].xx[k];
    }
    f << std::endl;
  }
  f.close();
}
