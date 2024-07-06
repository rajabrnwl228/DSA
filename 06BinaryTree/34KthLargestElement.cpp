        void helper(Node *root, int &x,int K,int&ans) {
       if(root==NULL)return ;
        helper(root->right,x,K,ans);
        x++;
        if(x==K){ans=root->data;K=INT_MIN;return ;}
        helper(root->left,x,K,ans);
    }

    int kthLargest(Node *root, int K)
    {
        //Your code here
        int ans=-1,x=0;
        helper(root,x,K,ans);
        return ans;
    }