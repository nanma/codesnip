#include <cstring>
#include <iostream>

using namespace std;

class CMyString {
 public:
  //  CMyString();
  CMyString(char* pData = NULL);
  //  CMyString(const CMyString& str);
  //  ~CMyString(void);
  CMyString& operator=(const CMyString &);
  void print();
 private:
  char* m_pData;
};

CMyString::CMyString(char* pData) {
  if (pData == NULL) {
    m_pData = new char[1]();    
  } else {
    m_pData = new char[strlen(pData) + 1];
    strcpy(m_pData, pData);
  }
  cout << "here 1" << endl;
}

CMyString& CMyString::operator=(const CMyString &rhs) {
  if (this == &rhs) {
    return *this;
  }
  delete []this->m_pData;
  this->m_pData = new char[strlen(rhs.m_pData) + 1];
  strcpy(m_pData, rhs.m_pData);
  return *this;
}

void CMyString::print() {
  cout << m_pData << endl;
}

int main() {
  //    char *s = new char[4]("abc");
  char s1[] = "C++";
  CMyString c1(s1);
  c1.print();
  char *s2 = "C--";
  CMyString c2(s2);
  c2.print();
  char *c = new char[5];
  c[0] = 'b';
  c[1] = 'a';
  c[2] = 'c';
  c[3] = 'd';
  cout << c << ":c" << endl;
  delete []c;
  return 0;
}
