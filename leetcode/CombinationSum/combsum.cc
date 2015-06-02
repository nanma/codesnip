#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int> >& result, vector<int>& inter, vector<int>& candidates, int gap, int start) {
  if (gap == 0) {
    result.push_back(inter);
    return;
  }
  for (int i = start; i < candidates.size(); i++) {
    if (gap < candidates[i]) return;
    inter.push_back(candidates[i]);
    dfs(result, inter, candidates, gap - candidates[i], i);
    inter.pop_back();
  }
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
  vector<vector<int> > result;
  vector<int> inter;
  sort(candidates.begin(), candidates.end());
  dfs(result, inter, candidates, target, 0);
  return result;
}

int main() {
  vector<int> c;
  c.push_back(2);
  c.push_back(3);
  c.push_back(5);
  c.push_back(7);
  vector<vector<int> > r = combinationSum(c, 7);
  for (int i = 0; i < r.size(); i++) {
    for (int j = 0; j < r[i].size(); j++) {
      cout << r[i][j] << ",";
    }
    cout << endl;
  }
}
