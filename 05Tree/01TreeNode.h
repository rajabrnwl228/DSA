#include<iostream>
#include<vector>
template <typename T>
class TreeNode
{
    public:
      T data;
      vector<TreeNode<T>*> children;
    
      TreeNode(int data)
      {
        this->data = data;
      }
      ~TreeNode()
      {
        for (int i = 0; i <children.size(); i++)
        {
          delete children[i];
        }
      }
};