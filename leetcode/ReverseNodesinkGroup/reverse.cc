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

ListNode *reverseKGroup(ListNode *head, int k) {
  if (head == NULL) return NULL;
  ListNode *tail = head;
  int i = 0;
  for (i = 0; i < k - 1 && tail != NULL; i++) {
    tail = tail->next;
  }
  if (i < k - 1 || tail == NULL) {
    return head;
  }
  ListNode *secondHead = NULL;
  if (tail != NULL) {
    secondHead = reverseKGroup(tail->next, k);
  }
  ListNode *firstHead = reverseList(head, k);
  head->next = secondHead;
  return firstHead;
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
  ListNode *e = new ListNode(5);
  ListNode *f = new ListNode(6);
  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;

  //  e->next = f;
  print(a);
  cout << endl;

  //  ListNode *t = reverseList(a, 3);
  ListNode *t = reverseKGroup(a, 3);
  print(t);
}
