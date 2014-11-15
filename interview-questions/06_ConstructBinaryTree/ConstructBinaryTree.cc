#include <iostream>
#include <stdexcept>

using namespace std;

struct BinaryTreeNode {
  int value;
  BinaryTreeNode* left;
  BinaryTreeNode* right;
};

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
    throw invalid_argument("Input invalid\n");
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


void Test(int* pre, int* in, int length) {
  //  int pre[8] = {1, 2, 4, 7, 3, 5, 6, 8};
  //  int in[8] = {4, 7, 2, 1, 5, 3, 8, 6};
  cout << "test begin:" << endl;
  BinaryTreeNode* tree = Construct(pre, in, length);
  PreOrder(tree);
  cout << endl;
  InOrder(tree);
  cout << endl;
}

void Test1(){
  int pre[8] = {1, 2, 4, 7, 3, 5, 6, 8};
  int in[8] = {4, 7, 2, 1, 5, 3, 8, 6};
  Test(pre, in, 8);
}

void Test2(){
  int pre[1] = {1};
  int in[1] = {1};
  Test(pre, in, 1);
}

void Test3()
{
  const int length = 5;
  int preorder[length] = {1, 2, 3, 4, 5};
  int inorder[length] = {5, 4, 3, 2, 1};
  Test(preorder, inorder, length);
  
}

void Test4()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 8, 1, 6, 3, 7};
    Test(preorder, inorder, length);
}

int main(){
  Test1();
  Test2();
  Test3();
  Test4();
  return 0;
}
