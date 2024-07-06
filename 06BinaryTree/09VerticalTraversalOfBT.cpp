    void helper(Node* root,multimap<pair<int,int>,int>&mp,int lev,int ind){
        if(root==NULL)return ;
        mp.insert({{ind,lev},root->data});
        helper(root->left,mp,lev+1,ind-1);
        helper(root->right,mp,lev+1,ind+1);
    }
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        multimap<pair<int,int>,int>mp;
        int lev=0,ind=0;
        helper(root,mp,lev,ind);
        vector<int>ans;
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }