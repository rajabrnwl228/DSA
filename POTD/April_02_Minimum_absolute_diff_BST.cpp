int prev=INT_MAX,diff=INT_MAX;
    void inorder(Node* root){
        if(root==NULL)return  ;
        inorder(root->left);
        if(prev!=INT_MAX);
        diff=min(diff,abs(root->data-prev));
        prev=root->data;
        inorder(root->right);
        
    }
    int absolute_diff(Node *root)
    {
        //Your code here
        inorder(root);
        return diff;
        
    }