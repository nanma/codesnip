#include <string>
#include <cstring>
#include <iostream>

using namespace std;

bool isUnique1(string str) {
  bool dic[256];
  memset(dic, false, sizeof(dic));
  for (int i = 0; i < str.size(); ++i) {
    int ind = str[i];
    if (dic[ind] == true) {
      return false;
    }
    dic[ind] = true;
  }
  return true;
}

bool isUnique2(string str) {
  int check = 0;
  for (int i = 0; i < str.size(); ++i) {
    int idx = str[i] - 'a';
    if (check & (1 << idx)) {
      return false;
    }
    check |= 1 << idx;
  }
  return true;
}

int main() {
  string s("abc");
  cout << isUnique1(s) << endl;
  string s1 = "abceab";
  cout << isUnique1(s1) << endl;
  s = "abc";
  cout << isUnique2(s) << endl;  
  s1 = "abceab";
  cout << isUnique2(s1) << endl;  

  return 0;
}
