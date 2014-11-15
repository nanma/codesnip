#include <iostream>
#include <string>
#include <sstream>

using std::string;

class FormatAmt {
 public:
  string amount(int dollars, int cents);
};

string FormatAmt::amount(int dollars, int cents){
  string result;
  int cnt = 0;
  int digit = 0;
  std::stringstream ss;
  if (cents == 0) {
    result = ".00";
  } else {
    while (cents != 0) {
      digit = cents % 10;
      cents /= 10;
      cnt++;
      ss << digit;
      result = ss.str() + result;
      ss.str("");
    }
    result = (cnt == 1) ? ".0" + result : "." + result;
  }
  cnt = 0;
  if (dollars == 0) {
    result = "0" + result;
  } else {
    while (dollars != 0) {
      digit = dollars % 10;
      dollars /= 10;
      cnt++;
      ss << digit;
      result = ss.str() + result;
      ss.str("");
      if (cnt % 3 == 0 && dollars != 0) {
        result = "," + result;
      }
    }
  }
  result = "$" + result;
  return result;
}  

int main()
{
  FormatAmt fa;
  std::cout << fa.amount(123456, 0) << std::endl;
  std::cout << fa.amount(49734321, 9) << std::endl;
  std::cout << fa.amount(0, 9) << std::endl;
  std::cout << fa.amount(249, 30) << std::endl;
  std::cout << fa.amount(1000, 1) << std::endl;
}
