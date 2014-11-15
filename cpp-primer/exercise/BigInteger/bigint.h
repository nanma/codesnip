#include <vector>
#include <string>
#include <iostream>
#include <istream>
#include <ostream>

using std::vector;
using std::string;

/* 一个大整数类，实现基本的加减乘运算，使用std::vector实现。
   change log:
   2013-10-09 实现正数的加减乘运算
 */
class bigint {
  friend std::ostream& operator<<(std::ostream&, const bigint&);
  friend std::istream& operator>>(std::istream&, bigint&);
public:
  bigint(): num(0) { }
  bigint(int val);
  bigint(const string&);

  bigint& operator+=(const bigint&);
  bigint& operator-=(const bigint&);
  bigint& operator*=(const bigint&);
  string strValue() const;
  string test(void);
  
private:
  vector<int> num;
};

bigint operator+(const bigint&, const bigint&);
bigint operator-(const bigint&, const bigint&);
bigint operator*(const bigint&, const bigint&);

std::ostream& operator<<(std::ostream&, const bigint &);
std::istream& operator>>(std::istream&, bigint &);
