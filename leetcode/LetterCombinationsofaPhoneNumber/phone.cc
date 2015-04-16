#include <vector>
#include <string>
#include <iostream>

using namespace std;

const string d[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void dfs(string &digits, int ind, string path, vector<string> &result) {
  if (ind == digits.size()) {
    result.push_back(path);
    return;
  }
  for (int i = 0; i < d[digits[ind] - '0'].size(); i++) {
    dfs(digits, ind + 1, path + d[digits[ind] - '0'][i], result);
  }
}

vector<string> letterCombinations(string digits) {
  vector<string> result;
  if (digits.size() == 0) return result;
  dfs(digits, 0, "", result);
  return result;
}

int main() {
  string a = "23";
  vector<string> res = letterCombinations(a);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }
}
