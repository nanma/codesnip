#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string sayNext(string s) {
  int count = 1;
  char last = s[0];
  string res = "";

  for (int i = 1; i < s.size(); i++) {
    if (s[i] == last) {
      count++;
    } else {
      stringstream ss;
      ss << count;
      res += ss.str() + last;
      last = s[i];
      count = 1;
    }
  }
  stringstream st;
  st << count;
  res += st.str() + last;
  return res;
}

string countAndSay(int n) {
  string s = "1";
  while (--n) {
    s = sayNext(s);
  }
  return s;
}

int main() {
  cout << countAndSay(3) << endl;
  cout << countAndSay(4) << endl;
  cout << countAndSay(5) << endl;
}
