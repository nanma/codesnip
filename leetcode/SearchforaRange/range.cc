#include <vector>
#include <iostream>

using namespace std;
/*
void search(vector<int>& nums, int target, int begin, int end, int& left, int& right) {
  while (begin <= end) {
    int mid = (begin + end) / 2;
    if (nums[mid] == target) {
      if (mid < left) left = mid;
      if (mid > right) right = mid;
      search(nums, target, begin, mid - 1, left, right);
      search(nums, target, mid + 1, right, left, right);
      break;
    }
    if (nums[mid] < target) {
      begin = mid + 1;
    } else {
      end = mid - 1;
                            }
  }
}
 */

void search(vector<int>& nums, int target, int begin, int end, int& left, int& right) {
  while (begin <= end) {
    int mid = (begin + end) / 2;
    if (nums[mid] == target) {
      if (mid < left) {
        left = mid;
        search(nums, target, begin, mid - 1, left, right);
      }
      if (mid > right) {
        right = mid;
        search(nums, target, mid + 1, end, left, right);
      }
      break;
    }
    if (nums[mid] < target) {
      begin = mid + 1;
    } else {
      end = mid - 1;
    }
  }
}

vector<int> searchRange(vector<int>& nums, int target) {
  vector<int> result;
  if (nums.size() == 0) return result;
  int left = nums.size(), right = -1;
  search(nums, target, 0, nums.size() - 1, left, right);
  if (left > right) left = right = -1;
  result.push_back(left);
  result.push_back(right);
  cout << left << ", " << right << endl;
  return result;
}

int main() {
  vector<int> nums;
  nums.push_back(5);
  nums.push_back(5);
//  nums.push_back(7);
//  nums.push_back(8);
//  nums.push_back(9);
//  nums.push_back(10);
  searchRange(nums, 5);
}
