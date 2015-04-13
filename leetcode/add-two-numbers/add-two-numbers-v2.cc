/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 *
 };
*/
#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode head(-1);
    ListNode *prev = &head;
    int carry = 0;
    for (ListNode *pa = l1, *pb = l2;
         pa != NULL || pb != NULL;
         pa = (pa == NULL) ? NULL : pa->next,
         pb = (pb == NULL) ? NULL : pb->next,
         prev = prev->next) {
      int a = (pa == NULL) ? 0 : pa->val;
      int b = (pb == NULL) ? 0 : pb->val;
      int value = (a + b + carry) % 10;
      carry = (a + b + carry) / 10;
      prev->next = new ListNode(value);
    }
    if (carry > 0) {
      prev->next = new ListNode(carry);
    }
    return head.next;
  }
};

int main() {
  Solution sol;
  ListNode *a = new ListNode(7);
  a->next = new ListNode(8);
  ListNode *b = new ListNode(6);
  b->next = new ListNode(9);
  ListNode *res = sol.addTwoNumbers(a, b);
  while (res != NULL) {
    std::cout << res->val;
    res = res->next;
  }
  std::cout << std::endl;

  res = sol.addTwoNumbers(a, NULL);
  while (res != NULL) {
    std::cout<< res->val;
    res = res->next;
  }
  std::cout << std::endl;
}
