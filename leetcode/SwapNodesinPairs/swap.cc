#include <vector>
#include <string>
#include <iostream>
#include <list>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *swapPairs(ListNode *head) {
  if (head == NULL || head->next == NULL) return head;
  ListNode *p, *q, *s, *t, *tmp;
  p = head;
  q = p->next;
  s = new ListNode(0);
  tmp = s;
  do {
    t = q->next;
    q->next = p;
    s->next = q;
    p->next = t;
    s = p;
    if (t == NULL || t->next == NULL) break;
    p = t;
    q = t->next;
  } while (true);
  return tmp->next;
}

void print(ListNode *h) {
  while (h != NULL) {
    cout << h->val << ", ";
    h = h->next;
  }
}

int main() {
  ListNode *a = new ListNode(1);
  ListNode *b = new ListNode(2);
  ListNode *c = new ListNode(3);
  ListNode *d = new ListNode(4);
  //  a->next = b;
  //  b->next = c;
  //  c->next = d;
  print(a);
  cout << endl;
  ListNode *t = swapPairs(a);
  print(t);
}
