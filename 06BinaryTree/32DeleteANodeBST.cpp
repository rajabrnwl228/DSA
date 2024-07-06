Node *deleteNode(Node *curr, int k) {
    // your code goes here
    if(curr==NULL)return NULL;
    if(curr->data==k){
        if(curr->left==NULL&&curr->right==NULL){
            return NULL;
        }
        if(curr->left==NULL){
            return curr->right;
        }
        if(curr->right==NULL){
            return curr->left;
        }
    
        Node* temp=curr->right;
        while(temp->left){
         temp=temp->left;   
        }
        temp->left=curr->left;
        curr->left=NULL;
        return curr->right;
    }
    if(k<=curr->data)
    curr->left=deleteNode(curr->left,k);
    else
    curr->right=deleteNode(curr->right,k);
    return curr;