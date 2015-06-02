#include <vector>
#include <iostream>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
 public:
  //Two factors sorting [start:end]
  bool static compare(const Interval& lhs, const Interval& rhs){
    return (lhs.start==rhs.start) ? lhs.end < rhs.end : lhs.start < rhs.start;
  }

  vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> result;
    if (intervals.size() <= 0) return result;
    //sort the inervals. Note: using the customized comparing function.
    sort(intervals.begin(), intervals.end(), compare);
    for(int i=0; i<intervals.size(); i++) {
      int size = result.size();
      // if the current intervals[i] is overlapped with previous interval.
      // merge them together
      if( size>0 && result[size-1].end >= intervals[i].start) {
        result[size-1].end = max(result[size-1].end, intervals[i].end);
      }else{
        result.push_back(intervals[i]);
      }
    }
    return result;
  }

  //Just reuse the solution of "Merge Intervals", quite straight forward
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    intervals.push_back(newInterval);
    return merge(intervals);
  }

};

int main() {
  return 0;
}
