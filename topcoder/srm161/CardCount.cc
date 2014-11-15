#include <string>
#include <vector>

using std::string;
using std::vector;

class CardCount {
 public:
  vector<string> dealHands(int numPlayers, string deck);
};

vector<string> CardCount::dealHands(int numPlayers, string deck){
  string deal;
  vector<string> res;
  for (int i = 0; i < numPlayers; ++i) {
    deal = "";
    for (int j = 0; j < deck.size() / numPlayers; ++j) {
      deal += deck[i + j * numPlayers];
    } 
    res.push_back(deal);
  }
  return res;
}
