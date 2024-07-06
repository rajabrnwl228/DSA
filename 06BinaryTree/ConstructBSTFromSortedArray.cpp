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
    BinaryTreeNode<int>* constructFromArray(int arr[],int s,int e){
      if(s>e){
        return NULL;
      }
      int mid=(s+e)/2;
      BinaryTreeNode<int>*root=new BinaryTreeNode<int>(arr[mid]);
      root->left=constructFromArray(arr,s,mid-1);
      root->right=constructFromArray(arr,mid+1,e);
      return root;
    }