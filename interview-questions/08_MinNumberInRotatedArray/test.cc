#include <iostream>
#include <set>
#include <functional>

using namespace std;
int main() {
  set<int> s;
  s.insert(4);
  s.insert(2);
  s.insert(6);
  set<int>::iterator iter = s.begin();
  for (; iter != s.end(); ++iter) {
    cout << *iter << ",";
  }
  cout << endl;
  multiset<int, greater<int> > ms;
  ms.insert(3);
  ms.insert(2);
  ms.insert(5);
  ms.insert(2);
  multiset<int>::iterator miter = ms.begin();
  for (; miter != ms.end(); ++miter) {
    cout << *miter << ",";
  }
  cout << endl;

}
    
