 bool helper(Node* root,pair<int,int> p){
        if(root==NULL)return 1;
        if(root->data>p.first&&root->data<p.second){
            pair<int,int>l={p.first,min(root->data,p.second)};
            pair<int,int>r={max(root->data,p.first),p.second};
            return helper(root->left,l)&&helper(root->right,r);
        }
        return 0;
    }
    bool isBST(Node* root) {
        // Your code here
        pair<int,int>p={INT_MIN,INT_MAX};
        return helper(root,p);
        
    }