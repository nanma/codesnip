#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void dfs(set<vector<int> >& result, vector<int>& inter, vector<int>& candidates, int gap, int start) {
  if (gap == 0) {
    result.insert(inter);
    return;
  }
  for (int i = start; i < candidates.size(); i++) {
    if (gap < candidates[i]) return;
    inter.push_back(candidates[i]);
    dfs(result, inter, candidates, gap - candidates[i], i + 1);
    inter.pop_back();
  }
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
  vector<vector<int> > result;
  set<vector<int> > res;
  vector<int> inter;
  sort(candidates.begin(), candidates.end());
  dfs(res, inter, candidates, target, 0);
  vector<vector<int> >::iterator it = result.begin();
  result.insert(it, res.begin(), res.end());
  return result;
}

int main() {
  vector<int> c;
  c.push_back(10);
  c.push_back(1);
  c.push_back(2);
  c.push_back(7);
  c.push_back(6);
  c.push_back(1);
  c.push_back(5);
  vector<vector<int> > r = combinationSum(c, 8);
  for (int i = 0; i < r.size(); i++) {
    for (int j = 0; j < r[i].size(); j++) {
      cout << r[i][j] << ",";
    }
    cout << endl;
  }
}
