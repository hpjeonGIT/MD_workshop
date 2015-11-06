#include <iostream>

void calc_sin_1(double x, double y);

void calc_sin_2(double x, double &y);

int main()
{ 
  double x = 3.1415, y = 10.;
  calc_sin_1(x,y);
  std::cout << x << " " << y << std::endl;
  calc_sin_2(x,y);
  std::cout << x << " " << y << std::endl;
  return 0;
}

