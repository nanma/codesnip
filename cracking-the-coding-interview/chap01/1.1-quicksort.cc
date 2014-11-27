#include <iostream>
#include <cstdlib>
#include <string>

int FLAG_ERROR = 0;

void swap(char* array, int a, int b) {
  char tmp = array[a];
  array[a] = array[b];
  array[b] = tmp;
  return;
}

int partition(char* array, int begin, int end) {
  int size = (end - begin + 1);
  if (array == NULL || begin < 0 || size <= 0) {
    return -1;
  }
  int tmp = rand() % size;
  swap(array, end, tmp);
  int last = -1;
  for (int i = 0; i < end; i++) {
    if (array[i] < array[end]) {
      swap(array, ++last, i);
    }
  }
  swap(array, ++last, end);
  return last;
}

void qSort(char* array, int begin, int end) {
  if (array == NULL || begin < 0 || begin >= end) {
    return;
  }
  int pivot = partition(array, begin, end);
  qSort(array, begin, pivot - 1);
  qSort(array, pivot + 1, end);
  return;
}

bool isUniq(char* array, int size) {
  if (array == NULL || size <= 0) {
    FLAG_ERROR = -1;
    return false;
  }
  qSort(array, 0, size - 1);
  for (int i = 1; i < size; i++) {
    if (array[i] == array[i - 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  char a[10] = "exdvuicda";
  bool res = isUniq(a, 9);
  //  bool res;
  //  qSort(a, 0, 8);
  std::cout << "result: " << res << " " << a << std::endl;
  
  std::string s = "aded";
  std::cout << s[2] << std::endl;
  s[2] = s[0];
  std::cout << s[2] << std::endl;
  return 0;
}
