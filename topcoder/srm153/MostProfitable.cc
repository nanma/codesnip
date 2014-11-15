#include <vector>
#include <string>

using std::vector;
using std::string;

class MostProfitable {
 public:
  string bestItem(vector<int> costs, vector<int> prices, vector<int> sales, vector <string> items);
};

string MostProfitable::bestItem(vector<int> costs, vector<int> prices, vector<int> sales, vector <string> items) {
  int maxProfit = 0, curProfit = 0, maxIndex = -1;
  for (int i = 0; i < costs.size(); ++i) {
    if (costs[i] > prices[i])
      continue;
    curProfit = (prices[i] - costs[i]) * sales[i];
    if (curProfit > maxProfit) {
      maxProfit = curProfit;
      maxIndex = i;
    }
  }
  if (maxIndex == -1)
    return "";
  else
    return items[maxIndex];
}

