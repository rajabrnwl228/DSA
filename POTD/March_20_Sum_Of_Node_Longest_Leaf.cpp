  pair<int,int>helper(Node* root){
        if(root==NULL)return {0,0};
        pair<int,int>x=helper(root->left);
        pair<int,int>y=helper(root->right);
        int rootsum=root->data;
        if(x.first==y.first)return {1+x.first,rootsum+max(x.second,y.second)};
        else if(x.first>y.first)return {1+x.first,rootsum+x.second};
        else return {1+y.first,rootsum+y.second};
        
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        return helper(root).second;
    }