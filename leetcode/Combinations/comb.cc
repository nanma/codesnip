#include <vector>
#include <iostream>
using namespace std;

void dfs(vector<vector<int> >& result, vector<int>& cur, int n, int k) {
  if (cur.size() == k) {
    result.push_back(cur);
    return;
  }
  int start = 1;
  if (cur.size() != 0) start = cur[cur.size() - 1] + 1;
  for(int i = start; i <= n; i++) {

    if (find(cur.begin(), cur.end(), i) == cur.end()) {

      cur.push_back(i);
      dfs(result, cur, n, k);
      cur.pop_back();
    }
  }
}

vector<vector<int> > combine(int n, int k) {
  vector<vector<int> > result;
  if (n <= 0 || k <= 0) return result;
  vector<int> cur;
  dfs(result, cur, n, k);
  return result;
}

int main() {
  vector<vector<int> > res = combine(4, 2);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[0].size(); j++) {
      cout << res[i][j] << ",";
    }
    cout << endl;
  }
}
