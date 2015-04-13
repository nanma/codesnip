#include <iostream>

bool isMatch(const char *s, const char *p) {
  if (*p == '\0') {
    return (*s == '\0');
  }
  if (*(p + 1) != '*') {
    if (*s == *p || (*p == '.' && *s != '\0')) {
      return isMatch(s + 1, p + 1);
    }
    return false;
  } else {
    while (*s == *p || (*p == '.' && *s != '\0')) {
      if (isMatch(s, p + 2)) {
        return true;
      }
      s++;
    }
    return isMatch(s, p + 2);
  }
}

int main() {
  const char *s = "aab";
  const char *p = "aa";
  std::cout << isMatch(s, p) << std::endl;
}
