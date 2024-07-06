#include <iostream>
#include <queue>
#include "BinaryTreeClass.h"
using namespace std;
#include <algorithm>
BinaryTreeNode<int> *takeInput()
{

  int rootdata;
  cout << "data :";
  cin >> rootdata;
  if (rootdata == -1)
    return NULL;
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
  BinaryTreeNode<int> *leftchild = takeInput();
  BinaryTreeNode<int> *rightchild = takeInput();
  root->left = leftchild;
  root->right = rightchild;
  return root;
}

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

void print(BinaryTreeNode<int> *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->data << ":";
  if (root->left)
    cout << "L" << root->left->data << " ";
  if (root->right)
    cout << "R" << root->right->data << endl;
  print(root->left);
  print(root->right);
}

int main()
{
  BinaryTreeNode<int> *root = takeInputLL();
  printLL(root);
  return 0;
}