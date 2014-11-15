#include <sstream>
#include <string>
#include <iostream>
class Time {
 public:
  std::string whatTime(int seconds);
};

std::string Time::whatTime(int seconds) {
  int hour = seconds / 3600;
  int minute = seconds % 3600 / 60;
  int second = seconds % 3600 % 60;
  std::stringstream result;
  result << hour << ":" << minute << ":" << second;
  return result.str();
}


int main()
{
  Time t;
  std::cout << t.whatTime(3600) << std::endl;
  return 0;
}
