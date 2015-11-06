#include <iostream>
#include <cmath>

void calc_sin_1(double x, double y)
{
   y = sin(x);
}

void calc_sin_2(double x, double &y)
{ 
   y = sin(x);
}

int main()
{ 
  double x = 3.1415, y = 10.;
  calc_sin_1(x,y);
  std::cout << x << " " << y << std::endl;
  calc_sin_2(x,y);
  std::cout << x << " " << y << std::endl;
  return 0;
}

