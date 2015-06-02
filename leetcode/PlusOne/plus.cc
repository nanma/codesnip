#include <vector>
#include <iostream>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
  vector<int> res(digits.size(), 0);
  if (digits.size() == 0) return res;
  int inc = 1;
  for (int i = digits.size() - 1; i >= 0; i--) {
    res[i] = (digits[i] + inc) % 10;
    inc = (digits[i] + inc) / 10;
  }
  if (inc != 0) {
    res.insert(res.begin(), inc);
  }
  return res;
}

int main() {
  vector<int> a;
  a.push_back(9);
  a.push_back(9);
  vector<int> res = plusOne(a);
  for (int i = 0; i < res.size(); i++)
    cout << res[i];
  cout << endl;
}
