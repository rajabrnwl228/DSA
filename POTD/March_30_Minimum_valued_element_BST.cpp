 int minValue(Node* root) {
        // Code here
        if(root==NULL)return -1;
        int ans=root->data;
        while(root!=NULL){
            ans=min(ans,root->data);
            root=root->left;
        }
        return ans;
        
    }