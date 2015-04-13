#include <iostream>
#include <string>

bool isPalindrome(int x) {
  if (x < 0) {
    return false;
  }
  int d = 1;
  while (x / d >= 10) {
    d *= 10;
  }
  int a, b;
  while (x > 0) {
    a = x / d;
    b = x % 10;
    if (a != b) {
      return false;
    }
    x = x % d / 10;
    d /= 100;
  }
  return true;
}

int main() {
  int a = 10001;
  std::cout << "a: " << a << ", " << isPalindrome(a) << std::endl;
  //  std::cout << 0 % 5;
}
