#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <climits>

using namespace std;

int threeSumClosest(vector<int> &num, int target) {
  //  if (num.size() < 3) return 0;
  sort(num.begin(), num.end());
  vector<int>::iterator last = num.end();
  int min_gap = INT_MAX;
  int result = 0;
  vector<int>::iterator b, c;
  for (vector<int>::iterator a = num.begin();
       a < prev(last, 2);
       a = upper_bound(a, prev(last, 2), *a)) {
    b = next(a);
    c = prev(last);
    while (b < c) {
      int sum = *a + *b + *c;
      int gap = abs(sum - target);
      if (gap < min_gap) {
        result = sum;
        min_gap = gap;
      }
      if (sum < target) b++;
      else c--;
    }
  }
  return result;
}

int main()
{
  int a[] = {1, 2, 4, 8, 16, 32, 64, 128};
  vector<int> n(a, a + sizeof(a) / sizeof(int));
  int result = threeSumClosest(n, 82);
  cout << result << endl;
  return 0;
}
