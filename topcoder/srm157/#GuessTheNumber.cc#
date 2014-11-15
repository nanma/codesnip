
class GuessTheNumber {
 public:
  int noGuesses(int upper, int answer);
};

int GuessTheNumber::noGuesses(int upper, int answer) {
  int num = 0, mid = 0, low = 1;
  while (mid != answer) {
    mid = (low + upper) / 2;
    num++;
    if (mid == answer) {
      break;
    } else if (mid > answer) {
      upper = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return num;
}

int main() {
  return 0;
}
