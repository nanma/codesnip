#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int bisearch(vector<int>& nums, int begin, int end, int target) {
  cout << "here: " << begin << ", " << end << endl;
  if (nums.size() == 0 || begin > end) return -1;
  int mid =  (begin + end) / 2;
  if (nums[mid] == target) return mid;
  if (nums[mid] < target) {
    if (nums[mid] < nums[end]) {
      int a = bisearch(nums, begin, mid - 1, target);
      if (a != -1) return a;
      int b = bisearch(nums, mid + 1, end, target);
      return b;
    } else if((nums[mid] > nums[end])) {
      return bisearch(nums, mid + 1, end, target);
    } else {
      return bisearch(nums, begin, end - 1, target);
    }
  } else {
    if (nums[mid] < nums[end]) {
      return bisearch(nums, begin, mid - 1, target);
    } else if((nums[mid] > nums[end])) {
      int a = bisearch(nums, begin, mid - 1, target);
      if (a != -1) return a;
      int b = bisearch(nums, mid + 1, end, target);
      return b;
    } else {
      return bisearch(nums, begin, end - 1, target);
    }
  }
}

int search(vector<int>& nums, int target) {
  if (nums.size() == 0) return -1;
  int begin = 0, end = nums.size() - 1;
  int ind = bisearch(nums, begin, end, target);
  return ind;
}

int main() {
  vector<int> v;
  n.push_back(1);
  cout << search(v, 0) << endl;
  bool a = -1;
  cout << "a: " << a << endl;
  vector<int> height;
  const int n = height.size();
  if (n == 0) return 0;
  int left[n];
  int *right = new int[n];
}
