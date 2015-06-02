#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
//3 20 15
//3 15 20
TreeNode* build(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir) {
  if (pl > pr) return NULL;
  TreeNode* root = new TreeNode(preorder[pl]);
  if (pl == pr) return root;
  vector<int>::iterator mid = find(inorder.begin() + il, inorder.begin() + ir + 1, preorder[pl]);
  int left_length = mid - inorder.begin() - il;
  TreeNode* left = build(preorder, pl + 1, pl + left_length, inorder, il, il + left_length - 1);
  TreeNode* right = build(preorder, pl + left_length + 1, pr, inorder, il + left_length + 1, ir);
  root->left = left;
  root->right = right;
  return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  int pr = preorder.size() - 1, ir = inorder.size() - 1;
  TreeNode* root = build(preorder, 0, pr, inorder, 0, ir);
  return root;
}

vector<vector<int> > levelOrder(TreeNode* root) {
  vector<TreeNode*> v;
  vector<vector<int> > res;
  if (root == NULL) return res;
  v.push_back(root);
  while (!v.empty()) {
    int k = v.size();
    vector<int> level;
    for (int i = 0; i < k; i++) {
      level.push_back(v[i]->val);
      if (v[i]->left) v.push_back(v[i]->left);
      if (v[i]->right) v.push_back(v[i]->right);
    }
    res.push_back(level);
    v.erase(v.begin(), v.begin() + k);
  }
  return res;
}

int main() {
  TreeNode* r;
  int a[] = {3, 9, 20, 15, 7};
  //  int a[] = {3, 20, 15};
  vector<int> vp(a, a + 5);
  int b[] = {9, 3, 15, 20, 7};
  //int b[] = {3, 15, 20};
  vector<int> vi(b, b + 5);
  r = buildTree(vp, vi);
  vector<vector<int> > res = levelOrder(r);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }

  int len = 5;
  int ** p = new int*[len];
}
