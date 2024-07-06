#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int> *takeInput()
{
  int data;
  cout << "Enter the data( Enter -1 for exit! ) : ";
  cin >> data;
  if (data == -1)
    return NULL;
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
  BinaryTreeNode<int> *leftchild = takeInput();
  BinaryTreeNode<int> *rightchild = takeInput();
  root->left = leftchild;
  root->right = rightchild;
  return root;
}
BinaryTreeNode<int> *takeINputLevelWise()
{
  int rootdata, leftdata, rightdata;
  cout << "Enter the root data( Enter -1 for exit!) : ";
  cin >> rootdata;
  if (rootdata == -1)
    return NULL;
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
  queue<BinaryTreeNode<int> *> queueNode;
  queueNode.push(root);
  while (queueNode.size() != 0)
  {
    BinaryTreeNode<int> *front = queueNode.front();
    queueNode.pop();
    cout << "Enter the left child of " << front->data << " (Enter -1 for exit! ) : ";
    cin >> leftdata;
    if (leftdata != -1)
    {
      BinaryTreeNode<int> *leftchild = new BinaryTreeNode<int>(leftdata);
      front->left = leftchild;
      queueNode.push(leftchild);
    }
    cout << "Enter the right child " << front->data << " (Enter -1 for exit! ) : ";
    cin >> rightdata;
    if (rightdata != -1)
    {
      BinaryTreeNode<int> *rightchild = new BinaryTreeNode<int>(rightdata);
      front->right = rightchild;
      queueNode.push(rightchild);
    }
  }
  return root;
}
void printLevelWise(BinaryTreeNode<int> *root)
{
  if (root == NULL)
  {
    return;
  }
  queue<BinaryTreeNode<int> *> queNode;
  queNode.push(root);
  while (queNode.size() != NULL)
  {
    BinaryTreeNode<int> *front = queNode.front();
    cout << front->data << " ";
    queNode.pop();
    if (front->left != NULL)
      queNode.push(front->left);
    if (front->right != NULL)
      queNode.push(front->right);
  }
}
void PreOrder(BinaryTreeNode<int> *root)
{
  if (root == NULL)
    return;
  cout << root->data << " : ";
  PreOrder(root->left);
  PreOrder(root->right);
}
void PostOrder(BinaryTreeNode<int> *root)
{
  if (root == NULL)
    return;
  PostOrder(root->left);
  PostOrder(root->right);
  cout << root->data << " ";
}
void InOrder(BinaryTreeNode<int> *root)
{
  if (root == NULL)
    return;
  InOrder(root->left);
  cout << root->data << " ";
  InOrder(root->right);
}
// count total number of node
int totalNode(BinaryTreeNode<int> *rootNode)
{
  if (rootNode == NULL)
    return 0;
  int count = 1;
  count += totalNode(rootNode->left);
  count += totalNode(rootNode->right);
  return count;
}
// count leaf Node
int leafNode(BinaryTreeNode<int> *rootNode)
{
  if (rootNode == NULL)
    return 0;
  if (rootNode->left == NULL && rootNode->right == NULL)
    return 1;
  int countLeaf = 0;
  countLeaf += leafNode(rootNode->left);
  countLeaf += leafNode(rootNode->right);
  return countLeaf;
}
// count internal node
int InternalNode(BinaryTreeNode<int> *rootNode)
{
  return totalNode(rootNode)-leafNode(rootNode);
}
// height of binary tree
int height(BinaryTreeNode <int>*rootNode)                                                    
{
  if (rootNode == NULL)
  {
    return 0;
  }
  int leftheight = height(rootNode->left);
  int rightheight = height(rootNode->right);
  return max(leftheight, rightheight) + 1;
}

//depth of binary tree
int depth(){
  
}

//diameter of a tree
int diameter(BinaryTreeNode<int>*root){
  if(root==NULL){
    return 0;
  }
  int a=height(root->left)+height(root->right);
  int b=diameter(root->left);
  int c=diameter(root->right);
  return max(a,max(b,c));
}
pair<int,int> heightDiameter(BinaryTreeNode<int>*root){
  if(root==NULL){
    pair<int,int>p;
    p.first=0;
    p.second=0;
    return p;

  }
  pair<int,int> leftans=heightDiameter(root->left);
  pair<int,int> rightans=heightDiameter(root->right);
  int ld=leftans.second;
  int lh=leftans.first;
  int rd=rightans.second;
  int rh=rightans.first;

  int height=1+max(lh,rh);
  int diameter=max(lh+rh,max(ld,rd));
  pair<int,int>p;
  p.first=height;
  p.second=diameter;
  return p;

}
int main()
{
  BinaryTreeNode<int> *root = takeINputLevelWise();
  cout << "PreOrderd Travseral :" << endl;
  PreOrder(root);
  cout << "PostOrderd Travseral :" << endl;
  PostOrder(root);
  cout << "\nInOrderd Travseral :" << endl;
  InOrder(root);
  cout << "\nlevel Wisr print " << endl;
  printLevelWise(root);
  cout<<"\n Diameter of the tree is :"<<diameter(root);
return 0;
}