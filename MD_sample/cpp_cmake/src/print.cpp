#include <iostream>
#include <fstream>
#include "md.h"

void MD::print_snap(int const& isnap)
{
    std::ofstream f;
    char name[256];
    sprintf(name, "snapshot%4.4d.xyz", isnap);
    f.open(name);
    f << Npt << std::endl;
    f << "#######" << std::endl;
    for (std::size_t i=0; i<Npt; i++) {
	f << "C " << q.xx[i] <<" "<<q.xy[i] << " " << q.xz[i] << std::endl;
    }
    f.close();
}
