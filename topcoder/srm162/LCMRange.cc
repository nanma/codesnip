#include <iostream>

class LCMRange {
 public:
  int lcm(int first, int last);
  int gcd(int a, int b) {
    while (b) {
      int tmp = a;
      a = b;
      b = tmp % b;
    }
    return a;
  }
};

int LCMRange::lcm(int first, int last) {
  int res = 1;
  for (int i = first; i <= last; ++i) {
    int d = gcd(res, i);
    res = res * i / d;
  }
  return res; 
}

int main() {
  LCMRange lcm;
  std::cout << lcm.lcm(1, 5) << std::endl; 
}
