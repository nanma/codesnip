#include <iostream>
#include <bitset>
using std::cout;
using std::bitset;
using std::endl;

int main()
{
  bitset<16> bitset1(0xfffe);
  cout << "bitset1: " << bitset1 << endl;
}
