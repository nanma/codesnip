#include <iostream>
#include <vector>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
  vector<string> result;
  int left = 0, right;
  if (words.size() == 0 || maxWidth < 0) return result;
  while (left < words.size()) {
    right = left;
    int length = words[left].size();
    while (right < words.size() - 1 &&
           length + (right + 1) - left +
           words[right + 1].size() <= maxWidth) {
      length += words[++right].size();
    }
    bool isLast = false;
    if (right == words.size() - 1) isLast = true;
    int totalSpace = maxWidth - length;
    int eachSapce = (left == right) ?
                   totalSpace : totalSpace / (right - left);
    int ext = (left == right) ? 0 : totalSpace % (right - left);
    string line = "";
    for (int i = left; i <= right; i++) {
      string space = string((i - left < ext) ? eachSapce + 1: eachSapce, ' ');
      if (isLast) {
        if (i < right) {
          space = " ";
        } else {
          space = string((totalSpace - (right - left)), ' ');
        }
      }
      line += words[i];
      if (i != right || left == right || isLast)
        line += space;
    }
    result.push_back(line);
    left = right + 1;
  }
//  string line = result[result.size() - 1];
//  string newLine = "";
//  bool inSpace = false;
//  int cnt = 0;
//  for (int i = 0; i < line.size(); i++) {
//    if (line[i] != ' ') {
//      newLine += line[i];
//      inSpace = false;
//    }
//    else {
//      if (!inSpace) {
//        newLine += line[i];
//        inSpace = true;
//      } else {
//        cnt++;
//      }
//    }
//  }
//  newLine += string(cnt, ' ');
//  result.pop_back();
//  result.push_back(newLine);
  return result;
}

int main() {
  string a[] = {"Don't","go","around","saying","the","world","owes","you","a","living;","the","world","owes","you","nothing;","it","was","here","first."};
  vector<string> v(a, a + 19);
  vector<string> vv;
  vv.push_back("");
  vector<string> r = fullJustify(vv, 2);
  for (int i = 0; i < r.size(); i++) {
    cout << r[i] << "|" << endl;
  }
}
