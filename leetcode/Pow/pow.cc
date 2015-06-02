#include <iostream>

double myPow(double x, int n) {
  if (n == 0) return 1;
  if (n == 1) return x;
  if (n < 0) return 1 / myPow(x, -(n + 1)) / x;
  double half = myPow(x, n / 2);
  if ((n & 1) == 1) return half * half * x;
  else return half *half;
}

int main() {
  std::cout << myPow(1.0, -2147483648) << std::endl;
}
