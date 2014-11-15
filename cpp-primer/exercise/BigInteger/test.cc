#include "bigint.h"
#include <iostream>
#include <vector>

using namespace std;

class A {
 public:
  void printA (A val);
 private:
  void print();
};

void A::printA(A val) {
  val.print();
}

void A::print() {
  cout << "a" << endl;
}

int main () {
  A a;
  A b;
  a.printA(b);
  vector<int> c(1, 2);
  vector<int>::iterator iter = c.begin();
  // --iter;
  *iter = 5;

  bigint bi("5222");
  //  cout << bi.strValue() << endl;
  return 0;
}
