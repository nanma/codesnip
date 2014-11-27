#include <iostream>
#include <cstring>

using namespace std;

void reverse(char *str, int length) {
  if (str == NULL || length <= 0) {
    return;
  }
  char *beg = str, *end = str;
  while (*end != '\0') {
    ++end;
  }
  --end;
  while (beg < end) {
    char tmp = *beg;
    *beg = *end;
    *end = tmp;
    ++beg;
    --end;
  }
  return;
}

int main() {
  char str[] = "abc";
  reverse(str, 4);
  cout << str << endl;
  //  wchar_t a = '和';
  //  wcout << a << endl;
}
