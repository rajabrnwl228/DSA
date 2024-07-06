 vector<int> inOrder(Node* root)
    {
        //code here
        vector<int>inOrd;
        Node* curr=root;
        while(curr){
            if(curr->left==NULL){
                inOrd.push_back(curr->data);
                curr=curr->right;
            }
            else {
                Node* prev=curr->left;
                while(prev->right!=NULL&&prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }else{
                    prev->right=NULL;
                    inOrd.push_back(curr->data);
                    curr=curr->right;
                    
                }
            }
        }
        return inOrd;
    }