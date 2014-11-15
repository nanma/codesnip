#include <cstring>
#include <iostream>

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

void Test(char* tGroup, char* str, char* exp) {
  cout << tGroup << " begin: " << endl;
  ReplaceBlank(str);
  if (str != NULL) {
    cout << str << ", ";
    if (strcmp(str, exp) == 0) {
      cout << "succeed" << endl;
    } else {
      cout << "failed" << endl;
    }
  }
  return;
}

char* Test1() {
  const int length = 15;
  char str[length] = "ab c d";
  char exp[length] = "ab%20c%20d";
  Test("Test1", str, exp);
}

char* Test2() {
  const int length = 15;
  char str[length] = "ab c ";
  char exp[length] = "ab%20c%20";
  Test("Test2", str, exp);
}

char* Test3() {
  const int length = 15;
  char str[length] = " ab c ";
  char exp[length] = "%20ab%20c%20";
  Test("Test3", str, exp);
}

char* Test4() {
  const int length = 15;
  char str[length] = "abc";
  char exp[length] = "abc";
  Test("Test3", str, exp);
}

char* Test5() {
  const int length = 15;
  char str[length] = "";
  char exp[length] = "";
  Test("Test3", NULL, NULL);
}


int main() {
  Test1();
  Test2();
  Test3();
  Test4();
  Test5();
  return 0;
}
