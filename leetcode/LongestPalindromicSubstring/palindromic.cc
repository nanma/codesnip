#include <iostream>
#include <string>

using std::string;

string longestPalindrome(string s) {
  int n = s.size();
  bool f[n][n];
  std::fill_n(&f[0][0], n * n, false);
  int max_len = 1, start = 0;
  for (int i = 0; i < n; i++) {
    f[i][i] = true;
  }
  for (int i = 1; i < n; i++) {
    if (s[i - 1] == s[i]) {
      f[i - 1][i] = true;
      max_len = 2;
      start = i - 1;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      std::cout << "j, i:" << j << ", " << i << "; " << s[j] << ", " << s[i] << ";";
      std::cout << f[j + 1][i - 1] << std::endl;
      if (j + 2 <= i && s[i] == s[j] && f[j + 1][i - 1]) {
        std::cout << "here: " << i << ", " <<j <<std::endl;;
        f[j][i] = true;
        if (i - j + 1 > max_len) {
          max_len = i - j + 1;
          start = j;
        }
      }
    }
  }
  return s.substr(start, max_len);
}

int main() {
  string s = "abcba";
  std::cout << longestPalindrome(s) << std::endl;
}
