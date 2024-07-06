
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int>ans;
        if(root==NULL)return ans;
        map<int,Node*>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            pair<Node*,int>p=q.front();
            q.pop();
            Node* val=p.first;
            int dis=p.second;
            mp[dis]=val;
            if(val->left!=NULL)q.push({val->left,dis-1});
            if(val->right!=NULL)q.push({val->right,dis+1});
            
        }
        for(auto i:mp){
            ans.push_back(i.second->data);
        }
        return ans;
    

    }