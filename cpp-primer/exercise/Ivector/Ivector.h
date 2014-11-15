#include <string>

template <class T> class Ivector {
public:
  typedef unsigned int size_type;
  Ivector();
  ~Ivector();
  void push_back(const T &);
  void pop_back();
  size_type size();
  T& back();
  T& front();
private:
  T* mem;
  size_type sz;
  int capacity;
};
