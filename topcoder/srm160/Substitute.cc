#include <string>

using std::string;

class Substitute {
 public:
  int getValue (string key, string code);
};

int Substitute::getValue(string key, string code) {
  int res = 0;
  string::size_type pos;
  for (int i = 0; i < code.size(); ++i) {
    pos = key.find(code[i]);
    if (pos != string::npos) {
      ++pos;
      res = res * 10 + pos % 10;
    }
  }
  return res;
}
