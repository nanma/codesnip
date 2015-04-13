#include <iostream>
#include <string>

using std::string;
string convert(string s, int nRows) {
  if (nRows == 1) {
    return s;
  }
  string *res = new string[nRows];
  int length = 0;
  int j = 0;
  while (length < s.size()) {
    j = 0;
    while (j < nRows && length < s.size()) {
      res[j++] += s[length++];
    }
    j = nRows - 2;
    while (j > 0 && length < s.size()) {
      res[j--] += s[length++];
    }
  }
  string result = "";
  for (int i = 0; i < nRows; i++) {
    result += res[i];
  }
  delete [] res;
  return result;
}

int main() {
  string s = "abc";
  std::cout << "|" << convert(s, 2) << "|" << std::endl;
  std::cout << s[4] ;
}
