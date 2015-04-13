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
    ListNode *result = NULL, *cur = NULL, *last = NULL;
    int inc = 0;
    while (l1 != NULL || l2 != NULL) {
      cur = new ListNode(0);
      if (result == NULL) {
        result = cur;
      } else {
        last->next = cur;
      }
      if (l1 != NULL) {
        cur->val += l1->val;
        l1 = l1->next;
      }
      if (l2 != NULL) {
        cur->val += l2->val;
        l2 = l2->next;
      }
      cur->val += inc;
      inc = cur->val / 10;
      cur->val %= 10;
      last = cur;
    }
    if (inc > 0) {
      cur = new ListNode(0);
      cur->val = inc;
      last->next = cur;
    }
    return result;
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
