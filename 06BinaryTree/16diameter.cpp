#include <iostream>
using namespace std;
#include "BinaryTreeClass.h"

BinaryTreeNode<int> *takeInputLL()
{

  int rootdata;
  cout << "rootdata :";
  cin >> rootdata;
  if (rootdata == -1)
    return NULL;
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(root->data);
  queue<BinaryTreeNode<int> *> que;
  que.push(root);
  while (que.size() != 0)
  {

    BinaryTreeNode<int> *front = que.front();
    que.pop();

    cout << "Enter left child of " << front->data << endl;
    int leftchilddata;
    cin >> leftchilddata;
    if (leftchilddata != -1)
    {
      BinaryTreeNode<int> *leftchild = new BinaryTreeNode<int>(leftchilddata);
      front->left = leftchild;
      que.push(leftchild);
    }

    cout << "Enter right child of " << front->data << endl;
    int rightchilddata;
    cin >> rightchilddata;
    if (rightchilddata != -1)
    {
      BinaryTreeNode<int> *rightchild = new BinaryTreeNode<int>(rightchilddata);
      front->right = rightchild;
      que.push(rightchild);
    }
  }
  return root;
}
void printLL(BinaryTreeNode<int> *root)
{
  if (root == NULL)
  {
    return;
  }
  queue<BinaryTreeNode<int> *> que;
  que.push(root);
  while (que.size() != 0)
  {
    BinaryTreeNode<int> *front = (que.front());
    que.pop();
    cout << front->data << ":";
    if (front->left != NULL)
    {
      cout << "L" << front->left->data;
      que.push(front->left);
    }
    if (front->right != NULL)
    {
      cout << "R" << front->right->data;
      que.push(front->right);
    }
    cout << endl;
  }
}
int height(BinaryTreeNode<int> *root)
{
  if (root == NULL)
  {
    return 0;
  }
  return 1 + max(height(root->left), height(root->right));
}
int diameter(BinaryTreeNode<int> *root)
{
  if (root == NULL)
  {
    return 0;
  }
  int option1 = height(root->left) + height(root->right);
  int option2 = diameter(root->left);
  int option2 = diameter(root->right);
  return max(option1, max(option2, option3));
}
pair<int, int> heightDiameter(BinaryTree<int> *root)
{
  if (root == NULL)
  {
    pair<int, int> p;
    p.first = 0;
    p.second = 0;
    return p;
  }
  pair<int, int> leftAns = heightDiameter(root->left);
  pair<int, int> rightAns = heightDiameter(root->right);
  int ld = leftAns.second;
  int lh = leftAns.first;
  int rd = rightAns.second;
  int rh = rightAns.first;
  int height = 1 + max(lh, rh);
  int diameter = max(lh + rh, max(ld, rd));
  pair<int, int> p;
  p.first = height;
  p.second = diameter;
  return p;
}

int main()
{
  BinaryTreeNode<int> *root = takeInputLL();
  printLL(root);

  return 0;
}