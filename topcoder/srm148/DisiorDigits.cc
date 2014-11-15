#include <iostream>

class DivisorDigits {
 public:
  int howMany(int number);
};

int DivisorDigits::howMany(int number) {
  int orig = number;
  int digit = 0;
  int count = 0;
  while(orig != 0) {
    digit = orig % 10;
    orig /= 10;
    if (digit == 0){
      continue;
    }
    if (number % digit == 0) {
      count++;
    }
  }
  return count;
}
