#include <vector>
#include <iostream>

using namespace std;

int getInt(vector<int> &vec) {
  return vec[0];
}

int main() {
  vector<int> vec;
  vec.push_back(2);
  vec.push_back(4);
  int &a = getInt(vec);
  a = 5;
  cout << vec[0] << endl;
  // int b = getInt(vec);
  // b = 7;
  // cout << vec[0] << endl;

  return 0;
}
