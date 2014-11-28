#include <iostream>
#include <cstdio>

char *compress(char* str, int size) {
  if (str == NULL || size <= 0) {
    return NULL;
  }
  char *strHead = str;
  char *res = new char[size];
  char *resHead = res;
  if (res == NULL) {
    return NULL;
  }
  char *ind = NULL;
  int length = 0;
  while (*str) {
    ind = str + 1;
    while (*ind == *str) {
      ind++;
    }
    *res++ = *str;
    length++;
    if (ind - str > 1) {
      int num = ind - str;
      int numTmp = num;
      int digit = 1;
      while (numTmp /= 10) {
        digit++;
      }
      char *numStr = new char[sizeof(char) * digit + 1];
      sprintf(numStr, "%d", num);
      char *nInd = numStr;
      while (*nInd) {
        *res++ = *nInd++;
        length++;
      }
      delete numStr;
    }
    str = ind;
    if (length >= size - 1) {
      break;
    }
  }
  *res = '\0';
  length++;
  if (length < size) {
    std::cout << "h: " << resHead << std::endl;
    return resHead;
  } else {
    return strHead;
  }
}

int main() {
  char str[] = "aabccccccccccxeuuuu";
  std::cout << str << " --> " << compress(str, 20) << std::endl;
}
