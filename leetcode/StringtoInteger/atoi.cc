#include <iostream>
#include <string>
#define MIN_INT  (-2147483647 - 1)
#define MAX_INT  2147483647

using std::string;

int atoi(string str) {
  int i = 0;
  while (str[i] == ' ') {
    i++;
  }
  if (i > 0)
    str = str.substr(i);
  i = 0;
  int minus = 1;
  if (str[0] == '+') {
    i = 1;
  } else if (str[0] == '-') {
    i = 1;
    minus = -1;
  }
  int res = 0;
  while (i < str.size() && '0' <= str[i] && str[i] <= '9') {
    if (res > 214748364) { //overflow int value.
      if (minus == 1) {
        return MAX_INT;
      } else {
        return MIN_INT;
      }
    } else if (res == 214748364) {
      if (minus == 1 && (str[i] - '0') > 7) {
        return MAX_INT;
      }
      if (minus == -1 && (str[i] - '0') > 8) {
        return MIN_INT;
      }
    }
    res = res * 10 + (str[i++] - '0');
  }
  res *= minus;
  return res;
}

int main() {
  string s = "2147483648";
  std::cout << atoi(s) << std::endl;
  s = "-2147483640";
  std::cout << atoi(s) << std::endl;

  //  int x = (1 << 31) - 1;
  //  std::cout << x;
}
