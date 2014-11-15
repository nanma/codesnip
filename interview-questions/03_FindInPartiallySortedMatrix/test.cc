#include <iostream>

int getSize(int p[]) {
  return sizeof(p);
}

int main()
{
  int a[] = {1, 2, 3, 4, 5};
  int *p = a;
  std::cout << sizeof(a) << ", " << sizeof(p) << ", " << getSize(a)  <<std::endl;
}
