#include <algorithm>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    map<int, int> m;
    vector<int> result;
    for (int i = 0; i < numbers.size(); i++) {
      if (m.count(numbers[i]) == 1 && numbers[i] * 2 == target) {
        result.push_back(m[numbers[i]] + 1);
        result.push_back(i + 1);
        return result;
      }
      m[numbers[i]] = i;
    }
    for (int i = 0; i < numbers.size(); i++) {
      if (m.find(target - numbers[i]) != m.end()) {
        int first = i + 1;
        int second = m[target - numbers[i]] + 1;
        if (first == second) {
          continue;
        }
        result.push_back(first);
        result.push_back(second);
        break;
      }
    }
    return result;
  }
};

int main() {
  int a[] = {1, 4, 5, 2};
  vector<int> b(a, a + 4);
  Solution sol;
  vector<int> res = sol.twoSum(b, 9);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << ", ";
  }
  cout << endl;
  return 0;
}
