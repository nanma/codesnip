#include <iostream>
#include <stdexcept>
#include <cstdio>

using namespace std;

struct BinaryTreeNode {
  int value;
  BinaryTreeNode* left;
  BinaryTreeNode* right;
};

bool isInvalidTree = false;

BinaryTreeNode* Construct(int* preorder, int* inorder, int length) {
  if (preorder == NULL || inorder == NULL || length <= 0) {
    return NULL;
  }
  BinaryTreeNode* root = new BinaryTreeNode;
  root->value = *preorder;
  int* tmp = inorder;
  int tmpLength = 0;
  while (*tmp != *preorder && tmpLength < length) {
    ++tmp;
    ++tmpLength;
  }
  if (tmp != preorder && tmpLength == length) {
    //throw invalid_argument("Input invalid\n");
    //cout << "No";
    isInvalidTree = true;
    return NULL;
  }
  int leftLen = tmp - inorder;
  BinaryTreeNode* left = Construct(preorder + 1, inorder, leftLen);
  BinaryTreeNode* right = Construct(preorder + leftLen + 1, tmp + 1, length - leftLen - 1);
  root->left = left;
  root->right = right;
  return root;
}

void InOrder(BinaryTreeNode* root) {
  if (root == NULL) {
    //cout << "Empty tree." << endl;
    return;
  }
  InOrder(root->left);
  cout << root->value << ",";
  InOrder(root->right);
}

void PreOrder(BinaryTreeNode* root) {
  if (root == NULL) {
    //cout << "Empty tree." << endl;
    return;
  }
  cout << root->value << ",";
  PreOrder(root->left);
  PreOrder(root->right);
}

void PostOrder(BinaryTreeNode* root) {
  if (root == NULL) {
    return;
  }
  PostOrder(root->left);
  PostOrder(root->right);
  cout << root->value << " ";
}

int main(){
  int length = 0;
  while (scanf("%d", &length) != EOF) {
    int* pre = new int[length];
    int* in = new int [length];
    for (int i = 0; i < length; ++i) {
      scanf("%d", &pre[i]);
    }
    for (int i = 0; i < length; ++i) {
      scanf("%d", &in[i]);
    }
    BinaryTreeNode* tree = Construct(pre, in, length);
    if (isInvalidTree == true) {
      cout << "No";
      isInvalidTree = false;
    }
    else {
      PostOrder(tree);      
    }
    cout << endl;
  }
  return 0;
}
