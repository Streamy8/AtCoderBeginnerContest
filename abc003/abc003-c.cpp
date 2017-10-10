#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>

#include <iomanip>
#include <limits>

int n;
int k;
int *r;

int main()
{
  std::cin >> n;
	std::cin >> k;
  r = new int[n];

  double rate = 0.0;

  for (int i=0; i<n ;i++) {
    std::cin >> r[i];
  }

  std::sort(r,r+n);

  for (size_t i = n-k; i < n; i++) {
    if(rate < r[i]){
      rate = (rate+r[i])/2.0;
    }
  }

  std::cout << std::setprecision(12) << rate<< std::endl;
  return 0;
}
