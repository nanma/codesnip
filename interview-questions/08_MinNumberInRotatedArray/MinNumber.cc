#include <iostream>
#include <stdexcept>
#include <string>

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

int test(string test, int* array, int length) {
  cout << test << " begins: ";
  int min = minNumber(array, length);
  cout << min << endl;
}

int test1() {
  int a[5] = {3, 4, 5, 1, 2};
  test("test1", a, 5);
}

int test2() {
  int a[6] = {3, 4, 5, 6, 1, 2};
  test("test2", a, 6);
}

int test3() {
  int a[6] = {1, 2, 3, 4, 5, 6};
  test("test3", a, 6);
}

int test4() {
  int a[2] = {2, 1};
  test("test4", a, 2);
}

int test5() {
  int a[5] = {0, 1, 1, 1, 1};
  test("test5", a, 5);
}

int test6() {
  int a[5] = {1, 0, 1, 1, 1};
  test("test5", a, 5);
}

int test7() {
  int a[5] = {1, 1, 1, 0, 1};
  test("test5", a, 5);
}

int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();

  // 典型输入，单调升序的数组的一个旋转
  int array1[] = {3, 4, 5, 1, 2};
  test("1", array1, sizeof(array1) / sizeof(int));

  // 有重复数字，并且重复的数字刚好的最小的数字
  int array2[] = {3, 4, 5, 1, 1, 2};
  test("1", array2, sizeof(array2) / sizeof(int));

  // 有重复数字，但重复的数字不是第一个数字和最后一个数字
  int array3[] = {3, 4, 5, 1, 2, 2};
  test("1", array3, sizeof(array3) / sizeof(int));

  // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
  int array4[] = {1, 0, 1, 1, 1};
  test("1", array4, sizeof(array4) / sizeof(int));

  // 单调升序数组，旋转0个元素，也就是单调升序数组本身
  int array5[] = {1, 2, 3, 4, 5};
  test("1", array5, sizeof(array5) / sizeof(int));

  // 数组中只有一个数字
  int array6[] = {2};
  test("1", array6, sizeof(array6) / sizeof(int));
}
