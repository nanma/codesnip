#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int digits(int n) {
  int s = 1;
  for (; n > 9; n = n / 10) {
    s++;
  }
  return s;
}

int sumNumbers(TreeNode* root) {
  if (root == NULL) return 0;
  int res = 0;
  if (root->left == NULL && root->right == NULL) res = root->val;
  if (root->left) {
    int left = sumNumbers(root->left);
    cout << "l:" << left << endl;
    int n = digits(left);
    res = root->val * pow(10, n) + left;
    cout << "r:" << res << endl;
  }
  if (root->right) {
    int right = sumNumbers(root->right);
    int n = digits(right);
    res += root->val * pow(10, n) + right;
  }
  return res;
}

int main() {
  TreeNode* a = new TreeNode(0);
  TreeNode* b = new TreeNode(1);
  b->right = a;
  cout << sumNumbers(b) << endl;
}
