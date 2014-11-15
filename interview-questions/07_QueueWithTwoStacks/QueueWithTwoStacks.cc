#include <stack>
#include <iostream>
#include <stdexcept>

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
    throw exception();
  }
  T head = stack2.top();
  stack2.pop();
  return head;
}

int main() {
  CQueue<int> q;
  q.appendTail(4);
  q.appendTail(2);
  cout << q.deleteHead() << endl;
  cout << q.deleteHead() << endl;
  cout << q.deleteHead() << endl;
}   
