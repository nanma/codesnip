#include <iostream>
int main()
{
  int amount = 0;
  int value;
  while(std::cin >> value){
    if(value < 0){
      amount++;
    }
  }
  std::cout << "amount of negtive numbers:\n"
            << amount << std::endl;
}
