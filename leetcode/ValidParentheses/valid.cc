#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s) {
  stack<char> t;
  for (int i = 0; i < s.size(); i++) {
    switch (s[i]) {
        case ')':
          if (t.empty() || t.top() != '(') return false;
          else t.pop();
          break;
        case ']':
          if (t.empty() || t.top() != '[') return false;
          else t.pop();
          break;
        case '}':
          if (t.empty() || t.top() != '{') return false;
          else t.pop();
          break;
        default:
          t.push(s[i]);
      }
  }
  if (t.empty()) return true;
  else return false;
}

int main() {
  string a = "]";
  std::cout <<isValid(a) << endl;
}
