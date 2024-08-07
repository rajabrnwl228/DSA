#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode
{
public:
  T data;
  BinaryTreeNode<T> *left;
  BinaryTreeNode<T> *right;

  BinaryTreeNode(T data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

using namespace std;
#include "solution.h"

BinaryTreeNode<int> *takeInput()
{
  int rootData;

  cin >> rootData;
  if (rootData == -1)
  {
    return NULL;
  }
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
  queue<BinaryTreeNode<int> *> q;
  q.push(root);
  while (!q.empty())
  {
    BinaryTreeNode<int> *currentNode = q.front();
    q.pop();
    int leftChild, rightChild;
    cin >> leftChild;
    if (leftChild != -1)
    {
      BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
      currentNode->left = leftNode;
      q.push(leftNode);
    }

    cin >> rightChild;
    if (rightChild != -1)
    {
      BinaryTreeNode<int> *rightNode =
          new BinaryTreeNode<int>(rightChild);
      currentNode->right = rightNode;
      q.push(rightNode);
    }
  }
  return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root)
{
  queue<BinaryTreeNode<int> *> q;
  q.push(root);
  q.push(NULL);
  while (!q.empty())
  {
    BinaryTreeNode<int> *first = q.front();
    q.pop();
    if (first == NULL)
    {
      if (q.empty())
      {
        break;
      }
      cout << endl;
      q.push(NULL);
      continue;
    }
    cout << first->data << " ";
    if (first->left != NULL)
    {
      q.push(first->left);
    }
    if (first->right != NULL)
    {
      q.push(first->right);
    }
  }
}
void mirrorBinaryTree(BinaryTreeNode<int> *root)
{
  // Write your code here
  if (root == NULL)
  {
    return;
  }
  if (root->left != NULL && root->right != NULL)
  {
    BinaryTreeNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;
  }
  else if (root->left == NULL && root->right != NULL)
  {
    root->left = root->right;
    root->right = NULL;
  }
  else if (root->right == NULL && root->left != NULL)
  {
    root->right = root->left;
    root->left = NULL;
  }
  mirrorBinaryTree(root->left);
  mirrorBinaryTree(root->right);
}
int main()
{
  BinaryTreeNode<int> *root = takeInput();
  mirrorBinaryTree(root);
  printLevelATNewLine(root);
}
