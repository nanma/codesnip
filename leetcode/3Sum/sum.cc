#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

vector<vector<int> > threeSum(vector<int> &num) {
  vector<vector<int> > result;
  if (num.size() < 3) return result;
  sort(num.begin(), num.end());
  vector<int>::iterator last = num.end();
  int target = 0;
  for (vector<int>::iterator a = num.begin();
       a < prev(last, 2);
       a = upper_bound(a, prev(last, 2), *a)) {
    for (vector<int>::iterator b = next(a);
         b < prev(last);
         b = upper_bound(b, prev(last), *b)) {
      int c = target - *a - *b;
      if (binary_search(next(b), last, c)) {
        int array[3] = {*a, *b, c};
        vector<int> vec(array, array + 3) ;
        result.push_back(vec);
      }
    }
  }
  return result;
}

void printMatrix(vector<vector<int> > &matrix)
{
  for(int i=0; i<matrix.size(); i++){
    printf("{");
    for(int j=0; j< matrix[i].size(); j++) {
      printf("%3d ", matrix[i][j]) ;
    }
    printf("}\n");
  }
  cout << endl;
}

int main()
{
  int a[] = {-1, 1, 1, 1, -1, -1, 0, 0, 0};
  vector<int> n(a, a+sizeof(a)/sizeof(int));
  vector< vector<int> > result = threeSum(n);
  printMatrix(result);
  return 0;
}
