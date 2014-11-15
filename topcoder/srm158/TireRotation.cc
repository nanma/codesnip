#include <string>
#include <iostream>

using std::string;

class TireRotation {
 public:
  int getCycle(string initial, string current);
};

int TireRotation::getCycle(string initial, string current) {
  int i = 0;
  string trans = initial;
  for (i = 0; i < 4; ++i) {
    std::cout << trans << " " << current << std::endl;
    if (trans == current) {
      return ++i;
    }
    trans = trans.substr(3, 1) + trans.substr(2, 1) + trans.substr(0, 2);
  }
  return -1;
}

int main() {
  TireRotation tr;
  std::cout << tr.getCycle("ABCD", "DCAB") << std::endl;
}
