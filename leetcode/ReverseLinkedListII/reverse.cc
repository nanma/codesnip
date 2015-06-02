#include <iostream>
#include <climits>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseList(ListNode * head, int k) {
  if (head == NULL) return NULL;
  ListNode *prev = NULL, *cur = head, *next = head->next;
  int n = 0;
  while (next != NULL && n < k - 1) {
    cur->next = prev;
    prev = cur;
    cur = next;
    next = next->next;
    n++;
  }
  cur->next = prev;
  return cur;
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
  ListNode* hh = new ListNode(0);
  hh->next = head;
  int k = (n - m) + 1;
  ListNode* pp = hh, *q = hh;
  while (m-- > 1)
    pp = pp->next;
  while (n-- > 0)
    q = q->next;
  ListNode* p = pp->next, *qn = q->next;
  reverseList(p, k);
  pp->next = q;
  p->next = qn;
  return hh->next;
}

int main() {
  ListNode* a = new ListNode(1);
  ListNode* b = new ListNode(2);
  ListNode* c = new ListNode(3);
  ListNode* d = new ListNode(4);
  ListNode* e = new ListNode(5);
  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;

//  while(a != NULL) {
//    cout << a->val<< ",";
//    a = a->next;
//  }
//  cout << endl;

  ListNode* r = reverseBetween(a, 5, 5);
  //  ListNode* r = reverseList(a + 1, 2);
  while(r != NULL) {
    cout << r->val<< ",";
    r = r->next;
  }
  cout << endl;

  long i = long(INT_MIN) - 1;
  long j = INT_MIN;
  cout << i << ", " << j << endl;
}
