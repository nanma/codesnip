#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode* t){
  while (t != NULL) {
    cout << t->val << ", ";
    t = t->next;
  }
  cout << endl;
}

ListNode* partition(ListNode* head, int x) {
  if (head == NULL) return NULL;
  ListNode* left_head = new ListNode(0), *right_head = new ListNode(0);
  ListNode* left_cur = left_head, *right_cur = right_head;
  for ( ; head; head = head->next) {
    if (head->val < x) {
      left_cur->next = head;
      left_cur = left_cur->next;
    } else {
      right_cur->next = head;
      right_cur = right_cur->next;
    }
  }
  left_cur->next = right_head->next;
  right_cur->next = NULL;
  return left_head->next;
}

int main() {
  ListNode x(5);
  ListNode y(1);
  ListNode z(1);
  x.next = &y;
  y.next = &z;

  ListNode a(1);
  ListNode b(4);
  ListNode c(3);
  ListNode d(2);
  ListNode e(5);
  ListNode f(2);

  //  x.next = &a;
  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &e;
  e.next = &f;
  ListNode* t = partition(&x, 3);
  print(t);
}
