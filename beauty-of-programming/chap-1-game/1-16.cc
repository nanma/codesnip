#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const double Threashold = 1E-6;
const int ResultValue = 24;
const int CardsNumber = 4;
double number[CardsNumber];
string result[CardsNumber];

bool PointsGame(int n) {
  if (n == 1) {
    if (fabs(number[0] - ResultValue) < Threashold) {
      cout << result[0] << endl;
      return true;
    } else {
      return false;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double a, b;
      string expa, expb;
      a = number[i];
      b = number[j];
      number[j] = number[n - 1];

      expa = result[i];
      expb = result[j];
      result[j] = result[n - 1];

      result[i] = '(' + expa + '+' + expb + ')';
    }
  }
}

int main() {

  return 0;
}
