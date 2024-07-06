void helper(Node* root, int sum,int lev,pair<int,int>&ans){
        if(lev==ans.first){
            ans.second=max(sum,ans.second);
        }
        if(lev>ans.first){
            ans.first=lev;
            ans.second=sum;
        }
        if(root==NULL)return ;
        sum+=root->data;
        helper(root->left,sum,lev+1,ans);
        helper(root->right,sum,lev+1,ans);
        
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        pair<int,int> ans={0,0};
        helper(root,0,0,ans);
        return ans.second;
        
        //code here
    }