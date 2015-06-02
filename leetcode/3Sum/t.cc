#include <string>
#include <climits>
#include <iostream>

using namespace std;

string minWindow(string s, string t) {
  if (s.empty()) return "";
  if (s.size() < t.size()) return "";

  const int ASCII_MAX = 256;
  int appeared_count[ASCII_MAX];
  int expected_count[ASCII_MAX];
  fill(appeared_count, appeared_count + ASCII_MAX, 0);
  fill(expected_count, expected_count + ASCII_MAX, 0);

  for (size_t i = 0; i < t.size(); i++) expected_count[int(t[i])]++;

  cout << expected_count[int('a')] << "," << int(t[0]) << endl;

  int minWidth = INT_MAX, min_start = 0;
  int wnd_start = 0;
  int appeared = 0;
  for (size_t wnd_end = 0; wnd_end < s.size(); wnd_end++) {
    if (expected_count[s[wnd_end]] > 0) {
      appeared_count[s[wnd_end]]++;
      if (appeared_count[s[wnd_end]] <= expected_count[s[wnd_end]])
        appeared++;
    }
    if (appeared == t.size()) {
      while (appeared_count[s[wnd_start]] > expected_count[s[wnd_start]] || expected_count[s[wnd_start]] == 0) {
        appeared_count[s[wnd_start]]--;
        wnd_start++;

      }
      if (minWidth > (wnd_end - wnd_start + 1)) {
        minWidth = wnd_end - wnd_start + 1;
        min_start = wnd_start;
      }
    }
  }
  //  cout << min_start << ", " << minWidth << endl;
  if (minWidth == INT_MAX) return "";
  else return s.substr(min_start, minWidth);
}

int main() {
  cout << minWindow("a", "a") << endl;
}
