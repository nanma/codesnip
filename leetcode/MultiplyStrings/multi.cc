#include <string>
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> bigint;

class solution {
 public:

 bigint make_bigint(string const& repr) {
  bigint n;
  for (int i = repr.size() - 1; i >=0; i--) {
    n.push_back(repr[i] - '0');
  }
  return n;
}

string to_string(bigint const& n) {
  string repr;
  int start = n.size() - 1;
  // skip leading zeros;
  while (n[start] == 0 && start > 0)
    start--;
  for (int i = start; i >= 0; i--) {
    char c = '0' + n[i];
    repr += c;
  }
  return repr;
}

bigint big_multiply(bigint const& x, bigint const& y) {
  bigint z(x.size() + y.size());
  for (size_t i = 0; i < x.size(); i++) {
    for (size_t j = 0; j < y.size(); j++) {
      z[i + j] += x[i] * y[j];
      z[i + j + 1] += z[i + j] / 10;
      z[i + j] = z[i + j] % 10;
    }
  }
  for (size_t i = 0; i < x.size() - 1; i++) {

  }
  return z;
}


string multiply(string num1, string num2) {
  return to_string(big_multiply(make_bigint(num1), make_bigint(num2)));
}

};

int main() {
  solution sol;
  //  cout << sol.to_string(sol.make_bigint("129932039203912345")) << endl;
  bigint a;
  a.push_back(0);
  a.push_back(0);
  cout << sol.to_string(a) << endl;
  cout << sol.multiply("100", "121") << endl;
}
