  pair<int,int>helper(Node* root){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int> left=helper(root->left);
        pair<int,int> right=helper(root->right);
        
        int ld=left.first;
        int rd=right.first;
        int dia=left.second+right.second+1;
        int d=max(dia,max(ld,rd));
        int h=max(left.second,right.second)+1;
        
        return {d,h};
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        return helper(root).first;
    }