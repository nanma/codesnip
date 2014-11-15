#include <iostream>

using namespace std;

int main()
{
  float a = 1.0;
  cout << "a:" << a << endl 
       << "reintepret: " << reinterpret_cast<int&>(a) << endl
       << "static: " << static_cast<int>(a) << endl;
}
