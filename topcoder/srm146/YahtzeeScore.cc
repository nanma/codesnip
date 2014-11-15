#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;

class YahtzeeScore {
 public:
  int maxPoints(vector <int> toss) {
    sort(toss.begin(), toss.end());
    vector<int>::iterator iter = toss.begin();
    int max = 0;
    int last_face = 0;
    int curr_sum = 0;
    while (iter != toss.end()) {
      if (*iter == last_face) {
        curr_sum += last_face;
      } else {
        curr_sum = *iter;
        last_face = *iter;
      }
      if (curr_sum > max) {
        max = curr_sum;
      }
      ++iter;
    }
    return max;
  }
};
int main()
{
  vector<int> vec;
  vec.push_back(5);
  vec.push_back(3);
  vec.push_back(5);
  vec.push_back(3);
  vec.push_back(3);
  YahtzeeScore ys;
  std::cout << ys.maxPoints(vec) << std::endl;
}
