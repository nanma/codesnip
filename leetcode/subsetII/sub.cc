#include <vector>
#include <set>
#include <iostream>

using namespace std;

void dfs(vector<int>& nums, int k,
         vector<int>& path, vector<vector<int> >& result) {
  result.push_back(path);
  for(int i = k; i < nums.size(); i++) {
    if (i != k && nums[i] == nums[i - 1]) continue;
    path.push_back(nums[i]);
    dfs(nums, i + 1, path, result);
    path.pop_back();
  }
}

void dfss(const vector<int> &s, vector<int>::iterator start,
          vector<int> &path, vector<vector<int> >& result) {
  result.push_back(path);
  for (vector<int>::iterator i = start; i < s.end(); i++) {
    if (i != start && *i == *(i - 1)) continue;
    path.push_back(*i);
    dfss(s, i+ 1, path, result);
    path.pop_back();
  }
}

vector<vector<int> > subsetsWithDup(vector<int>& nums) {
  vector<vector<int> > result;
  sort(nums.begin(), nums.end());
  vector<int> cur;
  dfs(nums, 0, cur, result);
  //  dfss(nums, nums.begin(), cur, result);
  return result;
}

int main() {
  int a[] = {1, 2, 2};
  vector<int> v(a, a+3);
  vector<vector<int> >res = subsetsWithDup(v);
  for (int i = 0; i < res.size(); i++) {
    cout << "[";
    for (int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << ",";
    cout << "]" << endl;
  }
}
