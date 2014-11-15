//------------------------------------
//  tree.cc
//------------------------------------

#include <iostream>
using std::cout;
using std::endl;

class Node
{
 public:
  virtual ~Node () {}
  virtual double Calc () const = 0;
};

class NumNode: public Node
{
 public:
  NumNode (double num) : _num (num) {}
  double Calc () const;
 private:
  const double _num;
};

class BinNode: public Node
{
 public:
  BinNode (Node * pLeft, Node * pRight)
      : _pLeft (pLeft), _pRight (pRight) {}
  ~BinNode ();
 protected: 
  Node * const _pLeft;
  Node * const _pRight;
};

class AddNode: public BinNode
{
 public:
  AddNode (Node * pLeft, Node * pRight)
      : BinNode (pLeft, pRight) {}
  double Calc () const;
};

class MultNode: public BinNode
{
 public:
  MultNode (Node * pLeft, Node * pRight)
      : BinNode (pLeft, pRight) {}
  double Calc () const;
};

BinNode::~BinNode ()
{
  delete _pLeft;
  delete _pRight;
}

double NumNode::Calc () const
{
  cout << "Numeric node "<< _num << endl;
  return _num;
}

double AddNode::Calc () const
{
  cout << "Adding\n";
  return _pLeft->Calc() + _pRight->Calc ();
}

double MultNode::Calc () const
{
  cout << "Multiplying\n";
  return _pLeft->Calc () * _pRight->Calc ();
}

int main ()
{
  // ( 20.0 + (-10.0) ) * 0.1
  Node* pNode1 = new NumNode (20.0);
  Node* pNode2 = new NumNode (-10.0);
  Node* pNode3 = new AddNode (pNode1, pNode2);
  Node* pNode4 = new NumNode (0.1);
  Node* pNode5 = new MultNode (pNode3, pNode4);
  cout << "Calculating the tree\n";
  double x = pNode5->Calc ();
  cout << x << endl;
  delete pNode5; // and all children
  return 0;
}
