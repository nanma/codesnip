#include <iostream>

void reverse(char* str) {
  if (str == NULL) {
    return;
  }
  char* left = str;
  char* right = str;
  while (*right) {
    right++;
  }
  right--;
  char tmp;
  while (left < right) {
    tmp = *left;
    *left = *right;
    *right = tmp;
    left++;
    right--;
  }
}

int main() {
  char s[6] = "abcde";
  std::cout << s << std::endl;
  reverse(s);
  std::cout << s << std::endl;
}
