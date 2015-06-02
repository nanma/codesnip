#include <vector>
#include <iostream>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
  int begin = 0, end = nums.size() - 1;
  while (begin <= end) {
    int mid = (begin + end) / 2;
    if (nums[mid] == target) return mid;
    if (nums[mid] < target) begin = mid + 1;
    else end = mid - 1;
  }
  return begin;
}

int main() {
  vector<int> res;
  res.push_back(1);
  res.push_back(3);
  res.push_back(5);
  res.push_back(6);
  cout << searchInsert(res, 5) << endl;
  cout << searchInsert(res, 2) << endl;
  cout << searchInsert(res, 7) << endl;
  cout << searchInsert(res, 0) << endl;
}
