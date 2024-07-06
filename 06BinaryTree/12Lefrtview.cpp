void helper(Node* root, int lev,vector<int>&ans){
    if(root==NULL)return ;
    if(lev==ans.size())ans.push_back(root->data);
    helper(root->left,lev+1,ans);
    helper(root->right,lev+1,ans);
}
vector<int> leftView(Node *root)
{
   // Your code here
       
        vector<int>ans;
        helper(root,0,ans);
        return ans;
}
//another method

vector<int> leftView(Node *root)
{
   // Your code here
       
        vector<int>ans;
        if(root==NULL)return ans;
        map<int,int>mp;
        queue<Node*>q;
        q.push(root);
        int l=0;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                Node* val=q.front();
                q.pop();
                if(mp.find(l)==mp.end()){
                    mp[l]=val->data;
                }
            if(val->left!=NULL)q.push(val->left);
            if(val->right!=NULL)q.push(val->right);
            }
            l++;
            
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
}
