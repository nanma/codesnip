#include <iostream>
#include <string>

bool isPerm(const std::string &s, const std::string &t) {
  std::string p = s + s;
  if (p.find(t) != -1) {
    return true;
  }
  return false;
}

int main() {
  std::string s = "abcd";
  std::string t = "bacd";
  std::cout << "res: " << isPerm(s, t) << std::endl;
}
