int getMaxWidth(Node* root) {
        if(root==NULL)return 0;
        int ans=0;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            ans=max(ans,s);
            for(int i=0;i<s;i++){
                Node* temp=q.front();
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }
        return ans;
        // Your code here
    }