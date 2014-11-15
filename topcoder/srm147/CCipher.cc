#include <iostream>
#include <string>

using std::string;

class CCipher {
 public:
  string decode(string cipherText, int shift);
};

string CCipher::decode(string cipherText, int shift)
{
  string result("");
  for (int i = 0; i < cipherText.size(); ++i) {
    cipherText[i] = (cipherText[i] - 'A' + 26 - shift) % 26 + 'A';
  }
  std::cout << cipherText << std::endl;
  return cipherText;
}

int main()
{
  CCipher cc;
  cc.decode("VQREQFGT", 2);
  return 0;
}
