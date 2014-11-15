#include <iostream>

int getID(int* list, int size) {
  int candidate = 0, times = 0;
  for (int i = 0; i < size; i++) {
    if (times == 0) {
      candidate = list[i];
      times++;
    } else {
      if (candidate == list[i]) {
        times++;
      } else {
        times--;
      }
    }
  }
  return candidate;
}

int main() {
  int array[14] = {2, 3, 3, 2, 3, 5, 3, 1, 2, 3, 1, 3, 3, 9};
  int res = getID(array, 14);
  std::cout << "result: " << res << std::endl;
  
  return 0;
}
