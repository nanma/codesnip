#include "Node.h"
#include <string>

using std::string;

class Calculator {
public:
  //  Calculator();
  Calculator(const string&);
  double result();
private:
  string buildRPExp(const string&);
  Node* buildTree(const string&);
};
