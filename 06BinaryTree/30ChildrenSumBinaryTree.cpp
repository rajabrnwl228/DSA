 int isSumProperty(Node *root)
    {
    
     if(root==NULL)return 1;
     if(root->left==NULL&&root->right==NULL)return 1;
     
     int lf=isSumProperty(root->left);
     int rf=isSumProperty(root->right);
     int ld=0,rd=0;
     if(root->left)ld=root->left->data;
     if(root->right)rd=root->right->data;
     
     if(root->data!=ld+rd){
         return 0;
     }
     return lf&&rf;
     
    }