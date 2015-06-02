#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int longestConsecutive(vector<int>& nums) {
  if (nums.size() == 0) return 0;
  int max = INT_MIN, min = INT_MAX;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] > max) max = nums[i];
    if (nums[i] < min) min = nums[i];
  }
  long size = 0;
  cout << min << ", " << max << endl;
  if ((min >= 0 && max >= 0) || (min <= 0 && max <= 0)) size = long(std::max(abs(max), abs(min))) + 1;
  else size = (long)abs(max) + (long)abs(min) + 1;
  cout << "aa" << endl;
  cout << "size:" << size << endl;
  vector<int> cnt(size, 0);
  cout << size << endl;
  for (int i = 0; i< nums.size(); i++) {

    cout << nums[i] - min << endl;
    cnt[nums[i] - min]++;
  }
  cout << "aa" << endl;
  int longest = 1, cur = 1;
  for (int i = 1; i < size; i++) {
    if (cnt[i] && cnt[i - 1]) cur++;
    else if (cnt[i] && !cnt[i - 1]) cur = 1;
    else if (!cnt[i] && cnt[i - 1]) {
      if (cur > longest) {
        longest = cur;
        cur = 0;
      }
    }
  }
  return longest;
}

int main() {
  int a[] = {2147483646,-2147483647,0,2,2147483644,-2147483645,2147483645};
  vector<int> v(a, a+ 7);
  cout << longestConsecutive(v) << endl;
}
