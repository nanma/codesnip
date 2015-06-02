#include "stdio.h"

bool isdigit(char c) {
  return (c>='0' && c<='9');
}

bool isspace(char c) {
  return (c==' ' || c =='\t' || c=='\n' || c=='\r' || c=='\f' || c=='\v');
}

bool isNumber(char *s) {
  bool point = false;
  bool hasE = false;

  //trim the space
  while(isspace(*s)) s++;
  //check empty
  if (*s == '\0' ) return false;
  //check sign
  if (*s=='+' || *s=='-') s++;

  const char *head  = s;
  for(; *s!='\0'; s++){
    // if meet point
    if ( *s == '.' ){
      if ( hasE == true || point == true){
        return false;
      }
      if ( s == head && !isdigit(*(s+1))  ){
        return false;
      }
      point = true;
      continue;
    }
    //if meet "e"
    if ( *s == 'e' ){
      if ( hasE == true || s == head) {
        return false;
      }
      s++;
      if ( *s=='+' || *s=='-' )  s++;
      if ( !isdigit(*s) ) return false;

      hasE = true;
      continue;
    }
    //if meet space, check the rest chars are space or not
    if (isspace(*s)){
      for (; *s != '\0'; s++){
        if (!isspace(*s)) return false;
      }
      return true;
    }
    if ( !isdigit(*s) ) {
      return false;
    }
  }
  return true;
}

int main() {
  bool a = isNumber("123e2");
  printf("%d\n", a);
  return 0;
}
