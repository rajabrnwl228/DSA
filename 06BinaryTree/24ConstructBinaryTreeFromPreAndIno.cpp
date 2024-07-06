   Node *helper(int pre[],int preS, int preE, int in[], int inS,int inE){
    if(inS>inE)
        return NULL;
    
    
    int rootdata=pre[preS];
    int rootIndex=-1;
    for(int i=inS;i<=inE;i++){
        if(in[i]==rootdata){
            rootIndex=i;
            break;
        }
    }

    int LSpre=preS+1;
    int REpre=preE;
    int LSin=inS;
    int LEin=rootIndex-1;
    int RSin=rootIndex+1;
    int REin=inE;    
    int LEpre=LSpre+(LEin-LSin);
    int RSpre=LEpre+1;
    
    Node *root=new Node (rootdata);
    root->left=helper(pre,LSpre,LEpre,in, LSin,LEin);
    root->right=helper(pre,RSpre,REpre,in, RSin,REin);
    return root;
}

    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        Node *root=helper(pre,0,n-1,in,0,n-1);
        return root;
        
