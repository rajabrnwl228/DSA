 pair<bool,int>helper(Node* root){
        if(root==NULL){
            return {1,0};
        }
        pair<bool,int> left=helper(root->left);
        pair<bool,int> right=helper(root->right);
        
        bool l=left.first;
        bool r=right.first;
        int h=max(left.second,right.second)+1;
        bool d=abs(left.second-right.second)<=1;
        
        if(l&&r&&d){
            return {1,h};
        }
        return {0,h};
        
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        return helper(root).first;
    }