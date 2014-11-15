#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using std::vector;
using std::string;
using std::stringstream;

class PrefixCode {
 public:
  string isOne(vector<string> words);
};

string PrefixCode::isOne(vector<string> words) {
  vector<string>::iterator iter = words.begin();
  vector<string>::iterator nIter = iter + 1;
  string result("Yes");
  size_t found;
  vector<string>::iterator prefix;
  while (iter != words.end() - 1) {
    while (nIter != words.end()) {
      if ((found = (*iter).find(*nIter)) == 0) {
        prefix = nIter;
      } else if ((found = (*nIter).find(*iter)) == 0) {
        prefix = iter;
      }
      if (found == 0) {
        size_t index = prefix - words.begin();      
        stringstream ss;
        ss << index;
        result = "No, " + ss.str();
        return result;
      }
      nIter++;
    }
    iter++;
  }
  return result;
}

int main()
{
  PrefixCode pc;
  vector<string> vec;
  vec.push_back("no");
  vec.push_back("nosy");
  vec.push_back("neighbors");
  vec.push_back("needed");
  std::cout << pc.isOne(vec) << std::endl;
}
