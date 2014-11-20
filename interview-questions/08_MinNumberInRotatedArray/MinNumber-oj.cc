#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdio>

using namespace std;

int minNumber(int* array, int length) {
  if (array == NULL || length <= 0) {
    throw new std::exception();
  }
  int low = 0, high = length - 1, mid = 0;
  while (low <= high) {
    if (array[low] < array[high]) {
      return array[low];
    }
    mid = low + (high - low) / 2;
    if (low == high) {
      return array[mid];
    }
    if (array[mid] == array[low]) {
      ++low;
    }
    if (array[mid] > array[low]) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
}

int main() {
  int size = 0;
  while (scanf("%d", &size) != EOF) {
    int* array = new int[size];
    for (int i = 0; i < size; ++i) {
      scanf("%d", &array[i]);
    }
    printf("%d\n", minNumber(array, size));
    delete [] array;
  }
}
