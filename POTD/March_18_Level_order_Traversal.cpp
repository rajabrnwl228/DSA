    vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int>ans;
      queue<Node*>que;
      que.push(node);
      while(que.size()!=0){
          Node *front=que.front();
          ans.push_back(front->data);
          que.pop();
          if(front->left!=NULL){
              que.push(front->left);
          }
          if(front->right!=NULL){
              que.push(front->right);
          }
          
      }
      return ans;
    }