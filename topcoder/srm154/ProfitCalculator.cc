/*
 * ProfitCalculator.cc
 *
 *  Created on: 2013年9月13日
 *      Author: manan
 */
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using std::string;
using std::vector;

class ProfitCalculator {
 public:
  int percent(vector <string> items);
};

int ProfitCalculator::percent(vector<string> items) {
  std::stringstream ss;
  double cost = 0, price = 0, totalCost = 0, totalPrice = 0;
  for (size_t i = 0; i < items.size(); ++i) {
	ss.clear();
    ss.str(items[i]);
    ss >> price >> cost;
    totalPrice += price;
    totalCost += cost;
  }
  int per = (totalPrice - totalCost) / totalPrice * 100;
  return per;
}

int main() {
  vector<string> vec;
  vec.push_back("012.99 008.73");
  vec.push_back("099.99 050.00");
  vec.push_back("123.45 101.07");
  ProfitCalculator pc;
  std::cout << pc.percent(vec) << std::endl;
  return 0;
}
