class Node {
 public:
  virtual ~Node() {}
  virtual double calc() const = 0;
};

class NumNode: public Node {
 public:
  NumNode(double num): _num(num) {}
  double calc() const;
 private:
  const double _num;
};

class BinNode: public Node {
 public:
  BinNode(Node *pLeft, Node *pRight): _pLeft(pLeft), _pRight(pRight) {}
  ~BinNode();
 protected:
  Node * const _pLeft;
  Node * const _pRight;
};

class AddNode: public BinNode {
 public:
  AddNode(Node *pLeft, Node *pRight): BinNode(pLeft, pRight) {}
  double calc() const;
};

class MultNode: public BinNode {
 public:
  MultNode(Node *pLeft, Node *pRight): BinNode(pLeft, pRight) {}
  double calc() const;
};
