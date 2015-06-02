#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<pair<int, int> >::const_iterator Iter;
size_t n;

void permute(Iter first, Iter last, vector<int> &p, vector<vector<int> >& result) {
  if (n == p.size()) {
    result.push_back(p);
    return;
  }
  for (Iter i = first; i != last; i++) {
    int count = 0;
    for (vector<int>::iterator j = p.begin(); j != p.end(); j++) {
      if (i->first == *j) {
        count++;
      }
    }
    if (count < i->second) {
      p.push_back(i->first);
      permute(first, last, p, result);
      p.pop_back();
    }
  }
}

vector<vector<int> > permuteUnique(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  unordered_map<int, int> count_map;
  for (int i = 0; i < nums.size(); i++) {
    if (count_map.find(nums[i]) == count_map.end())
      count_map[nums[i]] = 1;
    else
      count_map[nums[i]]++;
  }
  vector<pair<int, int> >elems;
  for (unordered_map<int, int>::iterator it = count_map.begin(); it != count_map.end(); it++) {
    elems.push_back(*it);
  }
  vector<vector<int> > result;
  vector<int> p;
  n = nums.size();
  permute(elems.begin(), elems.end(), p, result);
  return result;
}

int main() {
  vector<int> a;
  a.push_back(1);
  a.push_back(1);
  a.push_back(3);
  vector<vector<int> > res = permuteUnique(a);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << ", ";
    }
    cout << endl;
  }
}
