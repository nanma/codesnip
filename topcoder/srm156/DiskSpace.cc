#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

using std::vector;

class DiskSpace {
 public:
  int minDrives(vector<int> used, vector<int> total);
};

int DiskSpace::minDrives(vector<int> used, vector<int> total) {
  int usedAll = 0;
  for (int i = 0; i < used.size(); ++i) {
    usedAll += used[i];
  }
  sort(total.begin(), total.end(), std::greater<int>());
  int i = 0;
  while (usedAll > 0 && i < total.size()) {
    //std::cout << total[i] << " ";
    usedAll -= total[i++];
  }
  return i;
}

int main(){
  vector<int > used;
  used.push_back(300);
  used.push_back(525);
  used.push_back(110);
  vector<int > total;
  total.push_back(350);
  total.push_back(600);
  total.push_back(115);
  DiskSpace ds;
  std::cout << ds.minDrives(used, total) << std::endl;
  return 0;
}
