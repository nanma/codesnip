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
      number[i] = a + b;
      if(PointsGame(n - 1))
        return true;

      result[i] = '(' + expa + '-' + expb + ')';
      number[i] = a - b;
      if(PointsGame(n - 1))
        return true;

      result[i] = '(' + expb + '-' + expa + ')';
      number[i] = b - a;
      if(PointsGame(n - 1))
        return true;

      result[i] = '(' + expa + '*' + expb + ')';
      number[i] = a * b;
      if(PointsGame(n - 1))
        return true;

      if (b != 0) {
        result[i] = '(' + expa + '/' + expb + ')';
        number[i] = a / b;
        if(PointsGame(n - 1))
          return true;
      }
      if (a != 0) {
        result[i] = '(' + expa + '/' + expb + ')';
        number[i] = b / a;
        if(PointsGame(n - 1))
          return true;
      }

      number[i] = a;
      number[j] = b;
      result[i] = expa;
      result[j] = expb;
    }
  }
  return false;
}

int main() {
  int x;
  for (int i = 0; i < CardsNumber; i++) {
    char buffer[20];
    cout << "the " << i << "th number:";
    cin >> x;
    number[i] = x;
    sprintf(buffer, "%d", x);
    result[i] = buffer;
  }
  if (PointsGame(CardsNumber)) {
    cout << "Success." << endl;
  } else {
    cout << "Fail." << endl;
  }
  return 0;
}
