#include<iostream>
#include<string>
#include <algorithm>


int main()
{
  int x1, y1, x2, y2, x3, y3;
  std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  int ax, ay, bx, by;
  ax = x2 - x1;
  ay = y2 - y1;

  bx = x3 - x1;
  by = y3 - y1;

  std::cout<< (std::abs(ax*by-ay*bx))/2.0 << std::endl;

  return 0;
}
