

#include <iostream>
#include <queue>
using namespace std;
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
  ~BinaryTreeNode()
  {
    if (left)
      delete left;
    if (right)
      delete right;
  }
};
BinaryTreeNode<int>* insertIntoBST(BinaryTreeNode<int>*root,int data){
  if(root==NULL){
  root = new BinaryTreeNode<int>(data);
  return root;
  }
  if(data<root->data){
    root->left=insertIntoBST(root->left,data);
  return root;

  }
  if(data>root->data){
    root->right=insertIntoBST(root->right,data);
  return root;

  }
}
void takeInput(BinaryTreeNode<int>* &root)
{
  int data;
  cout<<"Enter the rootdata(-1 for exit:) "<<endl;
  cin >> data;
  // if (data == -1) {return;}
  while(data!=-1){
    insertIntoBST(root,data);
    cout<<"Enter the data (-1 for exit: )"<<endl;
    cin >> data;
  }

return ;
}
//recursive way
bool searchInBST(BinaryTreeNode<int> *root, int k)
{
  // Write your code here
  if (root == NULL)
    return 0;
    if(root->data==k){
      return 1;
    }
    if(root->data<k){
      return searchInBST(root->right,k);
    }
    else{
      return searchInBST(root->left,k);
    }
}
//iterative way
bool searchInBSTIterative(BinaryTreeNode<int>*root,int k){
  BinaryTreeNode<int>*temp=root;
  while(temp!=NULL){
    if(temp->data==k)
      return true;
    if(temp->data< k)
      temp=temp->right;
    else
      temp=temp->left;
  }
  return false;
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
BinaryTreeNode<int>* minVal(BinaryTreeNode<int>*root){
  BinaryTreeNode<int>*temp=root;
  while(temp->left!=NULL){
    temp=temp->left;
  }
  return temp;
}
BinaryTreeNode<int>* maxVal(BinaryTreeNode<int>*root){
  BinaryTreeNode<int>*temp=root;
  while(temp->right!=NULL){
    temp=temp->right;
  }
  return temp;
}
void printLevelWise(BinaryTreeNode<int> *root)
{
  if (root == NULL)
  {
    return;
  }
  queue<BinaryTreeNode<int> *> queNode;
  queNode.push(root);
  while (queNode.size()!=0)
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
BinaryTreeNode<int>*deleteBST(BinaryTreeNode<int>*root,int val){
  if(root==NULL)return root;
  if(root->data==val){
    if(root->left==NULL&&root->right==NULL){
      delete root;
      return NULL;
    }
    if(root->left==NULL&&root->right!=NULL){
      BinaryTreeNode<int>*temp=root->right;
      delete root;
      return temp;
    }
    if(root->left!=NULL&&root->right==NULL){
      BinaryTreeNode<int>*temp=root->left;
      delete root;
      return temp;
    }
    if(root->left!=NULL &&root->right!=NULL){
      int mini=minVal(root->right)->data;
      root->data=mini;
      root->right=deleteBST(root->right,mini);
      return root;
    }

  }
  if(root->data>val){
    root->left=deleteBST(root->left,val);
    return root;
  }
  else{
    root->right=deleteBST(root->right,val);
    return root;
  }
}
//check is tree BST or not
    bool isBSThelper(BinaryTreeNode<int>*root , int min, int max){
        if(root==NULL){
            return true;
        }
        if(root->data>max||root->data<min){
            return false;
        }
        return isBSThelper(root->left,min,root->data)&&isBSThelper(root->right,root->data,max);
    }
    bool isBST(BinaryTreeNode<int>* root) 
    {
        // Your code here
        return isBSThelper(root,INT_MIN,INT_MAX);
    }

int main()
{
  BinaryTreeNode<int> *root =NULL;
  takeInput(root);
  int k;
  cin >> k;
  cout << ((searchInBST(root, k)) ? "true" : "false");
  cout<<"printLevelWise : "<<endl;
  printLevelWise(root);
 cout<<"\npreorder traversal\n";
 PreOrder(root);
 cout<<"\npostorder traversal\n";
 PostOrder(root);
 cout<<"\nInOrder traversal\n";
 InOrder(root);
  BinaryTreeNode<int>* t=minVal(root);
 cout<<"\nMinimum value of BST : "<<t->data<<endl;
  BinaryTreeNode<int>* tr=maxVal(root);
 cout<<"\nMaxvalue value of BST : "<<tr->data<<endl;
 root=deleteBST(root, 30);
  cout<<"\npreorder traversal\n";
 PreOrder(root);
 cout<<"\npostorder traversal\n";
 PostOrder(root);
 cout<<"\nInOrder traversal\n";
 InOrder(root);
  BinaryTreeNode<int>* t=minVal(root);
 cout<<"\nMinimum value of BST : "<<t->data<<endl;
  BinaryTreeNode<int>* tr=maxVal(root);
 cout<<"\nMaxvalue value of BST : "<<tr->data<<endl;
   delete root;
}