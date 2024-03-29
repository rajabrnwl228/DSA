    vector <int> diagonalSum(Node* root) {
        // Add your code here
    queue<Node*> que;
    vector<int>ans;
    que.push(root);
    while(!que.empty()){
        int sum=0;
        queue<Node*>q2;
        while(!que.empty()){
           Node* temp=que.front();
           que.pop();
           while(temp){
               sum+=temp->data;
               if(temp->left!=NULL) q2.push(temp->left);
               temp=temp->right;
           }
        }
        ans.push_back(sum);
        que=q2;
    }
    return ans;
    }