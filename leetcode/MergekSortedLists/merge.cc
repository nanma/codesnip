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

ListNode *mergeKLists(vector<ListNode *> &lists) {
  if (lists.size() == 0) return NULL;
  ListNode *h = lists[0];
  for (int i = 1; i < lists.size(); i++) {
    h = mergeTwoLists(h, lists[i]);
  }
  return h;
}

/*
ListNode *mergeKLists(vector<ListNode *> &lists) {
  ListNode *head = new ListNode(0), *p = head;
  list<ListNode *> newlists;
  for (int i = 0; i < lists.size(); i++) {
    if (lists[i] != NULL) {
      newlists.push_back(lists[i]);
    }
  }
  while (newlists.size() > 0) {
    ListNode *n = NULL;
    int min = INT_MAX;
    list<ListNode *>::iterator ind;
    list<ListNode *>::iterator iter = newlists.begin();
    while (iter != newlists.end()) {
      if ((*iter)->val < min) {
        n = *iter;
        min = (*iter)->val;
        ind = iter;
      }
      iter++;
    }
    p->next = n;
    p = p->next;
    *ind = (*ind)->next;
    if (*ind == NULL) newlists.erase(ind);
  }
  head = head->next;
  return head;
}
*/

void print(ListNode *h) {
  while (h != NULL) {
    cout << h->val << ", ";
    h = h->next;
  }
}

int main() {
  vector<ListNode *> l;
  ListNode *a = new ListNode(2);
  ListNode *b = NULL;
  ListNode *c = new ListNode(-1);

  l.push_back(a);
  l.push_back(b);
  l.push_back(c);

  //  l.push_back(NULL);
  cout << l.size() << endl;

  ListNode *p = mergeKLists(l);
  print(p);
}
