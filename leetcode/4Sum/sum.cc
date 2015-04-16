#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <map>
#include <set>

using namespace std;

class Solution {
 public:
  /*vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector<vector<int> > result;
    if (num.size() < 4) return result;
    sort(num.begin(), num.end());
    vector<int>::iterator last = num.end();
    for (vector<int>::iterator a = num.begin();
    a < prev(last, 3);
    a = upper_bound(a, prev(last, 3), *a)) {
    for (vector<int>::iterator b = next(a);
    b < prev(last, 2);
    b = upper_bound(b, prev(last, 2), *b)) {
    for (vector<int>::iterator c = next(b);
    c < prev(last);
    c = upper_bound(c, prev(last), *c)) {
    int d = target - *a - *b - *c;
    if (binary_search(next(c), last, d)) {
    int array[4] = {*a, *b, *c, d};
    vector<int> vec(array, array + 4) ;
    result.push_back(vec);
    }
    }
    }
    }
    return result;
    }
  */

  void printMatrix(vector<vector<int> > &matrix) {
    for(int i=0; i<matrix.size(); i++){
      printf("{");
      for(int j=0; j< matrix[i].size(); j++) {
        printf("%3d ", matrix[i][j]) ;
      }
      printf("}\n");
    }
    cout << endl;
  }
  /*
  vector<vector<int> > fourSum(vector<int> &num, int target) {
    if (num.size() < 4) return vector<vector<int> >();
    sort(num.begin(), num.end());
    map<int, vector<pair<int, int> > > cache;
    for (size_t a = 0; a < num.size(); ++a) {
      for (size_t b = a + 1; b < num.size(); ++b) {
        cache[num[a] + num[b]].push_back(pair<int, int> (a, b));
      }
    }
    set<vector<int> > res;
    //    vector<int> group;
    for (size_t c = 2; c < num.size(); ++c) {
      for (size_t d = c + 1; d < num.size(); ++d) {
        const int value = target - num[c] - num[d];
        if (cache.find(value) != cache.end()) {
          for (size_t i = 0; i < cache[value].size(); i++) {
            if (c  <= cache[value][i].second) continue;
            group.clear();
            //            int array[4] = {num[cache[value][i].first], num[cache[value][i].second], num[c], num[d]};
            group.push_back(num[cache[value][i].first]);
            group.push_back(num[cache[value][i].second]);
            group.push_back(num[c]);
            group.push_back(num[d]);
            res.insert(group);
           // res.insert(vector<int> {num[cache[value][i].first], num[cache[value][i].second], num[c], num[d]});
          }
        }
      }
    }
    return vector<vector<int> >(res.begin(), res.end());;
  }
*/

  vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector<vector<int> > res;
    int numlen = num.size();
    if(num.size()<4)return res;
    sort(num.begin(),num.end());
    set<vector<int> > tmpres;
    for(int i = 0; i < numlen; i++)
    {
      for(int j = i+1; j < numlen; j++)
      {
        int begin = j+1;
        int end = numlen-1;
        while(begin < end)
        {
          int sum = num[i]+ num[j] + num[begin] + num[end];
          if(sum == target)
          {
            vector<int> tmp;
            tmp.push_back(num[i]);
            tmp.push_back(num[j]);
            tmp.push_back(num[begin]);
            tmp.push_back(num[end]);
            tmpres.insert(tmp);
            begin++;
            end--;
          }else if(sum<target)
            begin++;
          else
            end--;
        }
      }
    }
    set<vector<int> >::iterator it = tmpres.begin();
    for(; it != tmpres.end(); it++)
      res.push_back(*it);
    return res;
  }

};

int main()
{
  int a[] = {-1, 1, 1, 1, -1, -1, 0, 0, 0};
  vector<int> n(a, a+sizeof(a)/sizeof(int));
  Solution sol;
  vector< vector<int> > result = sol.fourSum(n, 0);
  sol.printMatrix(result);
  return 0;
}
