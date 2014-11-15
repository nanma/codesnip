#include <string>
#include <iostream>
using std::string;

class Quipu {
 public:
  int readKnots(string knots);
};

int Quipu::readKnots(string knots) {
  int result = 0;
  int i = 0;
  while (i < knots.size()) {
    while (knots[i] == '-') {
      result *= 10;
      ++i;
    }
    while (knots[i] == 'X') {
      result += 1;
      ++i;
    }
  }
  std::cout << result <<std::endl;
  return result / 10;
}

int main() {
  Quipu qp;
  std::cout << qp.readKnots("-XX-XXXX-XXX-") << std::endl; 
}
