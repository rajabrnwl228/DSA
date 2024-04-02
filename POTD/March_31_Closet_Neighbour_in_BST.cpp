int findMaxForN(Node* root, int n) {
        // code here
        if(root==NULL)return -1;
        int ans=INT_MIN;
        queue<Node*>que;
        que.push(root);
        while(!que.empty()){
            Node* node=que.front();
            que.pop();
            if(node->key<=n&&node->key>=ans){
                ans=node->key;
            }
            if(node->left!=NULL)que.push(node->left);
            if(node->right!=NULL)que.push(node->right);
        }
        if(ans==INT_MIN)
        return -1;
        return ans;
    }