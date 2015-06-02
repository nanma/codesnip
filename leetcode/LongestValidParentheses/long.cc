#include <string>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int longestValidParentheses(string s) {
  stack<int> t;
  int last = -1, max_len = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      t.push(i);
    } else {
      if (t.empty()) {
        last = i;
      } else {
        t.pop();
        if (t.empty()) max_len = max(max_len, i - last);
        else max_len = max(max_len, i - t.top());
      }
    }
  }
  return max_len;
}

int main() {
  string s = "";
  cout << longestValidParentheses(s) << endl;
}
