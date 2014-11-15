#include "Node.h"
#include <iostream>

using std::cout;
using std::endl;

double NumNode::calc() const {
  cout << "Numeric node:" << _num << endl;
  return _num;
}

BinNode::~BinNode() {
  delete _pLeft;
  delete _pRight;
}

double AddNode::calc() const {
  cout << "Adding\n";
  return _pLeft->calc() + _pRight->calc();
}

double MultNode::calc() const {
  cout << "Multiplying\n";
  return _pLeft->calc() * _pRight->calc();
}

// int main() {
//   Node *pNode1 = new NumNode(20);
//   Node *pNode2 = new NumNode(-8);
//   Node *pNode3 = new AddNode(pNode1, pNode2);
//   Node *pNode4 = new NumNode(0.1);
//   Node *pNode5 = new MultNode(pNode3, pNode4);
//   cout << "Calculating the tree\n";
//   double x = pNode5->calc();
//   cout << x << endl;
//   delete pNode5;
//   return 0;
// }
