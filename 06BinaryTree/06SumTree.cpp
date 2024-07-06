 pair<bool,int> helper(Node* root){
        if(root==NULL)return {true,0};
        if(root->left==NULL&&root->right==NULL)return {true,root->data};
         pair<bool,int> left=helper(root->left);
         pair<bool,int> right=helper(root->right);
         
         int d=root->data;
         bool l=left.first;
         bool r=right.first;
         bool check=root->data==(left.second+right.second);
         int sum=(root->data+left.second+right.second);
         if(l&&r&&check){
             return {1,sum};
         }
         return {0,sum};
         
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         return helper(root).first;
         
    }