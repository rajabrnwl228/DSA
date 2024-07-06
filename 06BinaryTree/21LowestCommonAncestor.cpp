Node*lcah(Node*root,int n1,int n2){
        if(root==NULL)
        return NULL;
        if(root->data==n1||root->data==n2){
            return root;
        }
        Node*ln=lcah(root->left,n1,n2);
        Node*rn=lcah(root->right,n1,n2);
        if(ln!=NULL &&rn!=NULL)
        return root;
        else if(ln!=NULL)
        return ln;
        else if(rn!=NULL)
        return rn;
        else return NULL;
    }
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
    Node*node=lcah(root,n1,n2);
    if(node==NULL)
    return NULL;
    else return node;
    }