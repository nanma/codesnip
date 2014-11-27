#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

bool isPerm(string s, string t) {
  if (s.length() != t.length()) {
    return false;
  }
  char *cs = new char[s.length() + 1];
  char *ct = new char[t.length() + 1];
  strcpy(cs, s.c_str());
  strcpy(ct, t.c_str());
  sort(cs, cs + s.length());
  sort(ct, ct + t.length());
  for (int i = 0; i < s.length(); i++) {
    if (cs[i] != ct[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  string s = "aedg", t = "gade";
  cout << "res: " << isPerm(s, t) << endl;
  return 0;
}
