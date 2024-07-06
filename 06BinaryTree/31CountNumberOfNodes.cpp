int leftHeight(Node* root){
      int h=0;
      while(root!=NULL){
          h++;
          root=root->left;
      }
      return h;
  }
  int rightHeight(Node* root){
      int h=0;
      while(root!=NULL){
          h++;
          root=root->right;
      }
      return h;
  }
    int countNodes(Node* root) {
        // Write your code here
        if(root==NULL)return 0;
        int lh=leftHeight(root);
        int rh=rightHeight(root);
        if(lh==rh)return (1<<rh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }