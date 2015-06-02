#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int>& height) {
  int n = height.size();
  int *max_left = new int[n];
  int *max_right = new int[n];
  fill(max_left, max_left + n, 0);
  fill(max_right, max_right + n, 0);

  for (int i = 1; i < n; i++) {
    max_left[i] = max(max_left[i - 1], height[i - 1]);
    max_right[n - i - 1] = max(max_right[n - i], height[n - i]);
  }
  int h = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    h = min(max_left[i], max_right[i]);
    if (h > height[i])
      sum += h - height[i];
  }
  delete max_left;
  delete max_right;
  return sum;
}

int main() {
  int array[] = {0, 2, 0};
  vector<int> v;
  //  vector<int>::iterator begin = v.begin();
  //  v.insert(begin, array, array + 3);
  v.push_back(0);
  v.push_back(2);
  v.push_back(0);
  cout << trap(v) << endl;
}
