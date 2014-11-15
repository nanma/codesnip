#include <iostream>
#include <sstream>
#include "bigint.h"

using std::stringstream;
using namespace std;

bigint::bigint(int val) {
  if (val < 0) {
    std::cout << "Invalid initial value: minus integer\n" << std::endl;
  }
  stringstream ss;
  ss << val;
  string str = ss.str();
  for (int i = 0; i < str.size(); ++i) {
    num.push_back(str[i] - '0');
  } 
 }

bigint::bigint(const string& val): num() {
  if (val.empty()) {
    std::cout << "Invalid initial value: empty string\n" << std::endl;
    return;
  }
  for (int i = 0; i < val.size(); ++i) {
    num.push_back(val[i] - '0');
  }
}

bigint& bigint::operator+=(const bigint& rhs) {
  vector<int>::iterator iter = num.end() - 1;
  vector<int> rNum = rhs.num;
  vector<int>::const_iterator rIter = rNum.end() - 1;
  int carry = 0;
  while (iter >= num.begin() && rIter >= rNum.begin()) {
    *iter = *iter + *rIter + carry;
    carry = 0;
    if (*iter >= 10) {
      *iter -= 10;
      carry = 1;
    }
    --iter;
    --rIter;
  }
  if (num.size() > rNum.size()) {
    while (carry == 1 && iter >= num.begin()) {
      *iter += carry;
      carry = 0;
      if (*iter >= 10) {
        *iter -= 10;
        carry = 1;
      } else {
        break;
      }
      --iter;
    }
  } else {
    while (rIter >= rNum.begin()) {
      int sum = *rIter + carry;
      carry = 0;
      if (sum >= 10) {
        sum -= 10;
        carry = 1;
      }
      num.insert(num.begin(), sum);
      --rIter;
    }
  }
  if (carry == 1) {
    num.insert(num.begin(), carry);
  }
  return *this;
}

bigint operator+(const bigint& lhs, const bigint& rhs) {
  bigint ret(lhs);
  ret += rhs;
  return ret;
}

bigint& bigint::operator-=(const bigint& rhs) {
  vector<int>::iterator iter = num.end() - 1;
  vector<int> rNum = rhs.num;
  vector<int>::iterator rIter = rNum.end() - 1;
  while (iter >= num.begin() && rIter >= rNum.begin()) {
    if (*iter < *rIter) {
      *(iter - 1) -= 1;
      *iter += 10;
    }
    *iter -= *rIter;
    --iter;
    --rIter;
  }
  if (num.size() > rNum.size()) {
    while (iter >= num.begin()) {
      if (*iter >= 0) {
        break;
      }
      *(iter - 1) -= 1;
      *iter += 10;
      --iter;
    }
  }
  iter = num.begin();
  while (*iter == 0 && iter < num.end() - 1) {
    iter = num.erase(iter);
  }
  return *this;
}

bigint operator-(const bigint& lhs, const bigint& rhs) {
  bigint ret(lhs);
  ret -= rhs;
  return ret;
}

bigint& bigint::operator*=(const bigint& rhs) {
  vector<int>::iterator iter;
  vector<int> rNum = rhs.num;
  vector<int>::iterator rIter = rNum.end() - 1;
  bigint ret(0);
  int rWeight = 1, weight = 1;
  while (rIter >= rNum.begin()) {
    weight = 1;
    iter = num.end() - 1;
    while (iter >= num.begin()) {
      int multi = *rIter * *iter;
      multi = multi * rWeight * weight;
      bigint bigMulti(multi);
      ret += bigMulti;
      weight *= 10;
      --iter;
    }
    rWeight *= 10;
    --rIter;
  }
  num.swap(ret.num);
  return *this;
}

bigint operator*(const bigint& lhs, const bigint& rhs) {
  bigint ret(lhs);
  ret *= rhs;
  return ret;
}

string bigint::strValue() const {
  string str;
  stringstream ss;
  for (int i = 0; i < num.size(); ++i) {
    ss.str("");
    ss << num[i];
    str.append(ss.str());
  }
  return str;
}

string bigint::test(void) {
  string s = "abc";
  return s;
}

ostream& operator<<(ostream& out, const bigint& val) {
  out << val.strValue();
  return out;
}

istream& operator>>(istream& in, bigint& val) {
  string str;
  in >> str;
  if (in) {
    vector<int> &number = val.num;
    number.clear();
    for (int i = 0; i < str.size(); ++i) {
      number.push_back(str[i] - '0');
    } 
  }
  return in;
}

int main() {
  bigint a("1111");
  //  std::cout<< a.strValue() << std::endl;
  bigint b("4");
  //  a += b;
  bigint c = a + b;
  //  std::cout<< c.strValue() << std::endl;
  c = a - b;
  std::cout << c.strValue() << std::endl;
  c = a * b;
  std::cout << c << std::endl;
  std::cin >> c;
  cout << c << endl;
  return 0;
}
