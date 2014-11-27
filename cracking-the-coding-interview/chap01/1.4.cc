#include <iostream>

void replace(char *str, int length) {
  if (str == NULL || length < 1) {
    return;
  }
  char *tail = str;
  int cnt = 0;
  while (*tail) {
    if (*tail++ == ' ') {
      cnt++;
    }
  }
  int newLength = length + cnt * 2;
  char *newTail = str + newLength;
  while (tail >= str) {
    if (*tail != ' ') {
      *newTail-- = *tail;
    } else {
      *newTail-- = '0';
      *newTail-- = '2';
      *newTail-- = '%';
    }
    tail--;
  }
  return;
}

int main() {
  //  char str[] = "a good storyxxxxxxxxx";
  //  str[12] = '\0';
  char str[] = "apple is st";
  replace(str, 11);
  std::cout << str << std::endl;
}
