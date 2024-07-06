bool helper(Node* root, int& k, int node,int& ans){
    if(root==NULL)return false;
    if(root->data==node){return true;}
    bool a=helper(root->left,k,node,ans);
    bool b=helper(root->right,k,node,ans);
    if(a||b)k--;
    if(k==0){
        k=INT_MAX;
        ans=root->data;
    }
    return a||b;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
 
 int ans=-1;
 helper(root,k,node,ans);
 return ans;
}