class A {
 public:
  void calc() { ; }
};

class B : public A {
 public:
  void recalc() { ; }
};

class Test {
 public:
  void does(A a) { a.calc(); }
};

int main() {
  return 0;
}
