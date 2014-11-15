#include <vector>

using std::vector;

class WidgetRepairs {
 public:
  int days(vector<int> arrivals, int numPerDay);
};

int WidgetRepairs::days(vector<int> arrivals, int numPerDay) {
  vector<int>::iterator iter = arrivals.begin();
  int leftNum = 0;
  int days = 0;
  while (iter != arrivals.end()) {
    leftNum += *iter;
    if (leftNum > 0) {
      days++;
      leftNum -= numPerDay;
      leftNum = (leftNum < 0) ? 0 : leftNum;
    }
    ++iter;
  }
  if (leftNum > 0) {
    days += leftNum / numPerDay;
    days = (leftNum % numPerDay == 0) ? days : days + 1;
  }
  return days;
}
