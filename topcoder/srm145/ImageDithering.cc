#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;

class ImageDithering {
 public:
  int count(string, vector<string>);
};

int ImageDithering::count(string dithered, vector<string>screen)
{
  vector<string>::iterator iter = screen.begin();
  int count = 0;
  while(iter != screen.end()) {
    for(int i = 0; i < (*iter).size(); i++) {
      if(dithered.find((*iter)[i], 0) != string::npos) {
        //std::cout << count << " ";
        count++;
      }
    }
    ++iter;
  }
  return count;
}

int main()
{
  ImageDithering id;
  vector<string> sc;
  sc.push_back("AAAAAAAA");
  sc.push_back("ABWBWBWA");
  sc.push_back("AWBWBWBA");
  sc.push_back("ABWBWBWA");
  sc.push_back("AWBWBWBA");
  sc.push_back("AAAAAAAA");
  std::cout << id.count("BW", sc) << std::endl;
  return 0;
}
