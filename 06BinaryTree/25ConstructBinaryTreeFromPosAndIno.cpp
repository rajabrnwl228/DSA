   Node *helper(int post[],int postS, int postE, int in[], int inS,int inE){
    if(inS>inE)
        return NULL;
    
    
    int rootdata=post[postE];
    int rootIndex=-1;
    for(int i=inS;i<=inE;i++){
        if(in[i]==rootdata){
            rootIndex=i;
            break;
        }
    }

    int LSpost=postS;
    int REpost=postE-1;
    int LSin=inS;
    int LEin=rootIndex-1;
    int RSin=rootIndex+1;
    int REin=inE;    
    int LEpost=LSpost+(LEin-LSin);
    int RSpost=LEpost+1;
    
    Node *root=new Node (rootdata);
    root->left=helper(post,LSpost,LEpost,in, LSin,LEin);
    root->right=helper(post,RSpost,REpost,in, RSin,REin);
    return root;
}
    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int n, int in[], int post[]) {
        // Your code here
           Node *root=helper(post,0,n-1,in,0,n-1);
        return root;
    }
