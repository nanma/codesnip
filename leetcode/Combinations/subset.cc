#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void dfs(vector<int>& nums, vector<vector<int> >& result, vector<int>& cur, int k) {
  if (nums.size() == k) {
    return;
  }
  int start = 0;
  if (cur.size() != 0) start = (find(nums.begin(), nums.end(), cur[cur.size() - 1]) - nums.begin()) + 1;
  for(int i = start; i < nums.size(); i++) {
    if (find(cur.begin(), cur.end(), nums[i]) == cur.end()) {
      cur.push_back(nums[i]);
      result.push_back(cur);
      dfs(nums, result, cur, k + 1);
      cur.pop_back();
    }
  }
}

vector<vector<int> > subsets(vector<int>& nums) {
  vector<vector<int> > result;
  if (nums.size() <= 0) return result;
  sort(nums.begin(), nums.end());
  vector<int> cur;
  result.push_back(cur);
  dfs(nums, result, cur, 0);
  return result;
}

int main() {
  int A[] = {4, 1, 0};
  vector<int> nums(A, A + 3);
  vector<vector<int> > res = subsets(nums);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << ",";
    }
    cout << endl;
  }
}
