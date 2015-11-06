int main()
{
  double *xx;
  xx = new double [3];
  xx[0] = xx[1] = xx[2] = 0.0;
  delete[] xx;
  return 0;
}
