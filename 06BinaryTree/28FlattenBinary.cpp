void flatten(Node *root)
    {
        //code here
        vector<int>inOrd;
        Node* curr=root;
        while(curr){
            if(curr->left!=NULL){
                Node* prev=curr->left;
                while(prev->right!=NULL&&prev->right!=curr){
                    prev=prev->right;
                }
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
        
    }