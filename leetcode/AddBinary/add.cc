#include <string>
#include <iostream>
using namespace std;

string addBinary(string a, string b) {
  string res = "";
  if (a.size() == 0 || b.size() == 0) return res;
  int i, j;
  int inc = 0;
  for (i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; i--, j--) {
    int ans = (a[i] - '0' + b[j] - '0' + inc) % 2;
    res = string(1, char('0' + ans)) + res;
    inc = (a[i] - '0' + b[j] - '0' + inc) / 2;
  }
  if (i >= 0)
    res = addBinary(a.substr(0, i + 1), string(1, char('0' + inc))) + res;
  else if (j >= 0)
    res = addBinary(b.substr(0, j + 1), string(1, char('0' + inc))) + res;
  else if (inc != 0)
    res = string(1, char('0' + inc)) + res;
  return res;
}

int main() {
  cout << addBinary("101", "11") << endl;
}
