#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

int main()
{
  vector<int> ivec;
  for(vector<int>::size_type ix = 0; ix != 10; ++ix)
    ivec.push_back(ix);
  cout << ivec[4];
}
