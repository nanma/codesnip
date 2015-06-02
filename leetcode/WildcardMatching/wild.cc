#include <string>
#include <iostream>

using namespace std;

bool isMatch(string s, string p) {
  bool star = false;
  int str, ptr, stmp = 0, ptmp = 0;
  for (str = 0, ptr = 0; str < s.size(); str++, ptr++) {
    switch (p[ptr]) {
      case '?':
        break;
      case '*':
        star = true;
        stmp = str;
        ptmp = ptr;
        while (p[ptr] == '*' && ptr < p.size()) {
          ptr++;
        }
        if (ptr == p.size()) return true;
        str = stmp - 1;
        ptr--;
        break;
      default:
        if (s[str] != p[ptr]) {
          if (!star) return false;
          stmp++;
          str = stmp - 1;
          ptr = ptmp - 1;
        }
    }
  }
  while (p[ptr] == '*' && ptr < p.size()) ptr++;
  return (ptr == p.size());
}

int main() {
  cout << isMatch("abefcdgiescdfimde", "ab*cd?i*de") << endl;
}
