#include <iostream>
int main()
{
  std::cout << "Input two nums:" << std::endl;
  int a, b;
  std::cin >> a >> b;
  for(int i = a; i <= b ; ++i){
    std::cout << i << std::endl;
  }
  return 0;
}
