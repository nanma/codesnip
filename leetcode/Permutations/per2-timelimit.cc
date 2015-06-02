#include <vector>
#include <iostream>
#include <set>

using namespace std;

void do_permute(vector<int>& nums, int depth, int total, set<vector<int> >& result, vector<int>& cur) {
  if (depth == total) {
    result.insert(cur);
    return;
  }
  for (int i = 0; i < nums.size(); i++) {
    int tmp = nums[i];
    //    cout << tmp << ",";
    cur.push_back(nums[i]);
    nums.erase(nums.begin() + i);
    do_permute(nums, depth + 1, total, result, cur);
    cur.pop_back();
    nums.insert(nums.begin() + i, tmp);
  }
}

vector<vector<int> > permuteUnique(vector<int>& nums) {
  vector<vector<int> > result;
  if (nums.size() == 0) return result;
  set<vector<int> > rset;
  vector<int> cur;
  do_permute(nums, 0, nums.size(), rset, cur);
  vector<vector<int> >::iterator pos = result.begin();
  result.insert(pos, rset.begin(), rset.end());
  return result;
}

int main() {
  vector<int> a;
  a.push_back(1);
  a.push_back(1);
  a.push_back(2);
  //  a.push_back(4);
  vector<vector<int> > res = permuteUnique(a);

  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << ", ";
    }
    cout << endl;
  }
}
