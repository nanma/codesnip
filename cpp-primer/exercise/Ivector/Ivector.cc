#include "Ivector.h"
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

template <class T> Ivector<T>::Ivector(): capacity(2), sz(0), mem(NULL) {
  mem = new T[capacity];
}

template <class T> void Ivector<T>::push_back(const T& val) {
  if (sz == capacity) {
    capacity *= 2;
    T* tmp = new T[capacity];
    memcpy(tmp, mem, sizeof(T) * sz);
    T* toDel = mem;
    mem = tmp;
    delete [] toDel;
  }
  mem[sz] = val;
  ++sz;
  return;
}

template <class T> Ivector<T>::~Ivector() {
  delete [] mem;
}

template <class T> void Ivector<T>::pop_back() {
  --sz;
}

template <class T> typename Ivector<T>::size_type Ivector<T>::size() {
  return sz;
}

template <typename T> T& Ivector<T>::back() {
  return mem[sz - 1];
}

template <typename T> T& Ivector<T>::front() {
  return mem[0];
}

int main() {
  Ivector<int> vec;
  vec.push_back(5);
  vec.push_back(18);
  cout << vec.back() << ", " << vec.front() << endl;
  vec.pop_back();
  cout << vec.back() << ", " << vec.front() << endl;
  vec.pop_back();
  vec.push_back(111);
  vec.push_back(999);
  vec.push_back(52);
  vec.push_back(181);
  cout << vec.back() << ", " << vec.front() << endl;
  Ivector<string> svec;
  svec.push_back("a");
  svec.push_back("s");
  cout << svec.back() << ", " << svec.front() << endl;
  string &s = svec.back();
  s = "d";
  cout << svec.back() << ", " << svec.front() << endl;
  return 0;
}
