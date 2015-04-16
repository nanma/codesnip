#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode(0), *p = head;
    while (l1 != NULL && l2 != NULL) {
      if (l1->val <= l2->val) {
        p->next = l1;
        p = l1;
        l1 = l1->next;
      } else {
        p->next = l2;
        p = l2;
        l2 = l2->next;
      }
    }
    if (l1 != NULL) p->next = l1;
    if (l2 != NULL) p->next = l2;
    p = head;
    head = head->next;
    delete p;
    return head;
  }
};

int main() {
  Solution sol;
  sol.mergeTwoLists(NULL, NULL);
}
