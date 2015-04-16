#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generate(int n, string s, int l, int r, vector<string> &result) {
  if (l == n) {
    result.push_back(s.append(n - r, ')'));
    return;
  }
  generate(n, s + '(', l + 1, r, result);
  if (l > r) generate(n, s + ')', l, r + 1, result);
}

vector<string> generateParenthesis(int n) {
  vector<string> result;
  generate(n, "", 0, 0, result);
  return result;
}

int main() {
  vector<string> res = generateParenthesis(3);
  vector<string>::iterator iter = res.begin();
  while (iter != res.end()) {
    std::cout << *iter << ", ";
    iter++;
  }
}
