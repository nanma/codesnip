#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
  vector<int> result;
  if (s.size() == 0 || words.size() == 0) return result;
  int n = s.size(), m = words.size(), l = words[0].size();
  if (n < m * l) return result;
  map<string, int> expect;
  for (int i = 0; i < words.size(); i++) {
    if (expect.find(words[i]) != expect.end()) expect[words[i]]++;
    else expect[words[i]] = 1;
  }

  for (int i = 0; i < l; i++){
    int winLeft = i;
    map<string, int> actual;
    int count = 0;
    for (int j = i; j < n - l + 1; j += l) {
      string word = s.substr(j, l);
      if (expect.find(word) == expect.end()) {
        actual.clear();
        count = 0;
        winLeft = j + l;
        continue;
      }
      if (actual.find(word) != actual.end()) {
        actual[word]++;
      } else {
        actual[word] = 1;
      }
      count++;
      if (actual[word] > expect[word]) {
        string tmp;
        do {
          tmp = s.substr(winLeft, l);
          count--;
          actual[tmp]--;
          winLeft += l;
        } while (tmp != word);
      }
      if (count == m) {
        result.push_back(winLeft);
        string tmp = s.substr(winLeft, l);
        actual[tmp]--;
        winLeft += l;
        count--;
      }
    }
  }
  return result;
}


int main() {
  string s = "aaa";
  vector<string> words;
  words.push_back("a");
  words.push_back("b");
  vector<int> res = findSubstring(s, words);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << ",";
  }
  cout << endl;
}
