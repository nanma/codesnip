/*
 * PickTeam.cc
 *
 *  Created on: 2013年9月13日
 *      Author: manan
 */
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <sstream>
#include <limits.h>
#include <algorithm>
#include <iostream>

using std::string;
using std::vector;
using std::priority_queue;
using std::pair;
using std::stringstream;

class cmp{
 public:
  bool operator() (pair<string, int> &p1, pair<string, int> &p2){
    return p1.second > p2.second; }
};

class PickTeam {
 public:
  vector<string> pickPeople(int teamSize, vector<string> people);
};

vector<string> PickTeam::pickPeople(int teamSize, vector<string> people) {
  string name;
  vector<int> relation(people.size());
  vector<string> names(people.size());
  priority_queue< pair<string, int>, vector< pair<string, int> >,  cmp> team, maxTeam;
  int maxSum = INT_MIN;
  for (int i = 0; i < people.size(); ++i) {
    stringstream ss(people[i]);
    ss >> name;
    names[i] = name;
  }
  for (int i = 0; i < people.size(); ++i) {
    stringstream ss(people[i]);
    ss >> name;
    int curSum = 0;
    for (int j = 0; j < people.size(); ++j) {
      ss >> relation[j];
      if (j == i)
    	continue;
      if (team.size() < teamSize - 1) {
    	team.push(make_pair(names[j], relation[j]));
        curSum += relation[j];
      } else if (relation[j] > team.top().second){
        curSum -= team.top().second;
        team.pop();
        team.push(make_pair(names[j], relation[j]));
        curSum += relation[j];
      }
    }
    if (curSum > maxSum) {
      maxSum = curSum;
      team.push(make_pair(name, 0));
      maxTeam = team;
    }
  }
  vector<string> resTeam;
  for (int m = 0; m < teamSize; ++m) {
    resTeam.push_back(maxTeam.top().first);
    maxTeam.pop();
  }
  sort(resTeam.begin(), resTeam.end());
  return resTeam;
}

int main()
{
  PickTeam pt;
  vector<string> vec;
  vec.push_back("ALICE 0 1 -1 3");
  vec.push_back("BOB 1 0 2 -4");
  vec.push_back("CAROL -1 2 0 2");
  vec.push_back("DAVID 3 -4 2 0");
  vector<string> rvec = pt.pickPeople(3, vec);
  for (int i = 0; i < rvec.size(); ++i) {
    std::cout << rvec[i] << std::endl;
  }
  return 0;
}
