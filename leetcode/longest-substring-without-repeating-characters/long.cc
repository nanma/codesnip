#include <iostream>
#include <algorithm>
#include <string>
#include <map>

class Solution {
 public:
  int lengthOfLongestSubstring1(std::string s) {
        int max_len = 0, len = 0;
        std::map<char, int> last;
        for (int i = 0; i < s.size(); i++, len++) {
          if (last.count(s[i]) != 0) {
            max_len = std::max(max_len, len);
            i = last[s[i]] + 1;
            len = 0;
            last.clear();
          }
          last[s[i]] = i;
        }
        return std::max(max_len, len);
      }

  int lengthOfLongestSubstring(std::string s) {
    int MAX_SIZE = 256;
    int last[MAX_SIZE];
    std::fill(last, last + MAX_SIZE, -1);
    int max_len = 0, len = 0;
    for (int i = 0; i < s.size(); i++, len++) {
      if (last[s[i]] >= 0) {
        max_len = std::max(max_len, len);
        i = last[s[i]] + 1;
        len = 0;
        std::fill(last, last + MAX_SIZE, -1);
      }
      last[s[i]] = i;
    }
    return std::max(max_len, len);
  }

};

int main() {
  Solution sol;
  std::string s = "abbbb";
  std::cout << sol.lengthOfLongestSubstring(s) << std::endl;
  //  std::map<char, int> m;
  //  std::cout << "test:" << m['a'] << ".";
}
