#include <iostream>

using namespace std;

void remDup(char* str, int length) {
  if (str == NULL || length <= 0) {
    return;
  }
  int tail = 0;
  int i, j;
  for (i = 0; i < length; ++i) {
    for (j = 0; j < tail; ++j) {
      if (str[i] == str[j]) {
        break;
      }
    }
    if (j == tail) {
      str[tail] = str[i];
      ++tail;
    }
  }
  return;
}

int main() {
  char s[] = "aaaaa";
  remDup(s, 6);
  cout << s << endl;
}
