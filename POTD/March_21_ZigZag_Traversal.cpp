 vector <int> zigZagTraversal(Node* root)
    {
        vector<int>res;
        if(root==NULL)
            return res;
      
        queue<Node*>que;
        que.push(root);
        bool flag=1;
        while(que.size()!=0){
            int size=que.size();
            vector<int>ans(size);
            
            for(int i=0;i<size;i++){
            Node*front=que.front();
            que.pop();
            int index=flag?i:size-i-1;
            ans[index]=front->data;
                if (front->left != NULL)
                    que.push(front->left);
    
                if (front->right != NULL)
                      que.push(front->right);
            }
            flag=!flag;
            for(auto i:ans){
                res.push_back(i);
            }
        }
        return res;
    	// Code here
    }