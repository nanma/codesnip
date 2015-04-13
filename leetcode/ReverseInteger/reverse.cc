#include <iostream>
#include <cmath>

int reverse(int x) {
  int res = 0;
  int minus = (x < 0) ? -1 : 1;
  x = x * minus;
  int MAX = (1 << 31) - 1;
  while (x > 0) {
    if (res > MAX / 10)
      return 0;
    res = res * 10 + x % 10;
    x /= 10;
  }
  res = res * minus;
  res = (res == MAX) ? 0 : res;
  return res;
}

int main() {
  int a = 1;
  std::cout << "res: " << reverse(a) << std::endl;
  //  int y = 964632435 * 10;
  //  std::cout << y;
  int x = (1 << 31) - 1 ;;
  x = x/10;
  std::cout << x << std::endl;
}
