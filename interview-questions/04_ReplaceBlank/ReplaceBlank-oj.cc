#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

void ReplaceBlank(char* str) {
  if (str == NULL) {
    return;
  }
  int cnt = 0;
  for (int i = 0; i < strlen(str); ++i) {
    if (str[i] == ' ') {
      ++cnt;
    }
  }
  if (cnt == 0) {
    return;
  }
  
  char* end = str + strlen(str);
  char* newEnd = str + strlen(str) + cnt * 2;
  int len = strlen(str);
  for (int i = 0; i < len + cnt * 2; ++i) {
    if (*end != ' ') {
      *newEnd = *end;
    } else {
      *newEnd-- = '0';
      *newEnd-- = '2';
      *newEnd = '%';
    }
    --end;
    --newEnd;
  }
  return;
}

// int main() {
//   char* str = new char[1000];
//   while (cin.getline(str, 100)) {
//     ReplaceBlank(str);
//     printf("%s\n", str);
//   }
//   delete [] str;
//   return 0;
// }

int main() {
  char str[1000];
  while (cin.getline(str, 1000)) {
    ReplaceBlank(str);
    printf("%s\n", str);
  }
  // delete [] str;
  return 0;
}
