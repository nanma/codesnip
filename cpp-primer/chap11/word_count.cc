#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using std::cin;
using std::string;
using std::vector;

bool isShorter(const string &s1, const string &s2)
{
  return s1.size() < s2.size();
}

bool GT6(const string &s)
{
  return s.size() >= 6;
}

int main()
{
  vector<string> words;
  string next_word;
  while(cin >> next_word) {
    words.push_back(next_word);
    //    std::cout << words[0] << std::endl;
  }
  sort(words.begin(), words.end());
  vector<string>::iterator end_unique = unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
  stable_sort(words.begin(), words.end(), isShorter);
  vector<string>::size_type wc = count_if(words.begin(), words.end(), GT6);
  std::cout << wc << " " << "word" << " 6 characters or longer" << std::endl;
  return 0;
}
