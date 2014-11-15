#include <stack>
#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <cstring>

using namespace std;

template <typename T> class CQueue
{
 public:
  CQueue(void);
  ~CQueue(void);

  void appendTail(const T& node);
  T deleteHead();

 private:
  stack<T> stack1;
  stack<T> stack2;
};

template <typename T> CQueue<T>::CQueue(void) {
  
}

template <typename T> CQueue<T>::~CQueue(void) {
  
}

template <typename T> void CQueue<T>::appendTail(const T& node) {
  stack1.push(node);
}

template <typename T> T CQueue<T>::deleteHead() {
  if (stack2.empty()){
    while (!stack1.empty()) {
      stack2.push(stack1.top());
      stack1.pop();
    }
  }
  if (stack2.empty()) {
    //throw exception();
    return -1;
  }
  T head = stack2.top();
  stack2.pop();
  return head;
}

int main() {
  CQueue<int> q;
  int cnt = 0;
  scanf("%d", &cnt);
  char str[10];
  int x = 0;
  for (int i = 0; i < cnt; ++i) {
    scanf("%s", str);
    if (strcmp(str, "PUSH") == 0) {
      scanf("%d", &x);
      q.appendTail(x);
    } else if(strcmp(str, "POP") == 0) {
      printf("%d\n", q.deleteHead());
    }
  }
}   
