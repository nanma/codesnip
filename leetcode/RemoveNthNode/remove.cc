#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
  if (head == NULL) return NULL;
  ListNode *right = head;
  int i = 0;
  for (; i < n  && right->next != NULL; i++) right = right->next;
  if (i < n) return head->next;
  ListNode *left = head;
  while(right->next != NULL) {
    left = left->next;
    right = right->next;
  }
  left->next = left->next->next;
  return head;
}

void print(ListNode *head) {
  while (head != NULL) {
    std::cout << head->val << std::endl;
    head = head->next;
  }
}

int main() {
  ListNode *a = new ListNode(5);
  ListNode *b = new ListNode(4);
  b->next = a;
  a = new ListNode(3);
  a->next = b;
  b = new ListNode(2);
  b->next = a;

  print(b);
  std::cout << std::endl;
  a = removeNthFromEnd(b, 4);
  print(a);
}
