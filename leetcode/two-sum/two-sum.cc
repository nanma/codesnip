#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> sNum = numbers;
    sort(sNum.begin(), sNum.end());
    int i = 0, j = sNum.size() - 1;
    vector<int> result;
    while (i < j) {
      if (sNum[i] + sNum[j] < target) {
        i++;
      } else if (sNum[i] + sNum[j] > target) {
        j--;
      } else {
        vector<int>::iterator first = find(numbers.begin(), numbers.end(), sNum[i]);
        vector<int>::iterator second = find(numbers.begin(), numbers.end(), sNum[j]);
        if (first == second) {
          second = find(first + 1, numbers.end(), sNum[j]);
        }
        if (first > second) {
          vector<int>::iterator tmp = first;
          first = second;
          second = tmp;
        }
        result.push_back(first - numbers.begin() + 1);
        result.push_back(second - numbers.begin() + 1);
        return result;
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
