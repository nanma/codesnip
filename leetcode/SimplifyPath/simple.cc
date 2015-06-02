#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
typedef string::iterator Iter;

string Simplifypath(string path) {
  vector<string> dirs;
  Iter j;
  for (Iter i = path.begin(); i < path.end(); ) {
    i++;
    j = find(i, path.end(), '/');
    string dir = string(i, j);
    if (!dir.empty() && dir != ".") {
      if (dir == "..") {
        if (!dirs.empty())
          dirs.pop_back();
      }
      else
        dirs.push_back(dir);
    }
    i = j;
  }

  string res = "";
  if (dirs.empty()) {
    res = "/";
  } else {
    for (int i = 0; i < dirs.size(); i++) {
      res  += "/" + dirs[i];
    }
  }
  return res;
}

int main() {
  cout << Simplifypath("/a/../") << endl;
}
