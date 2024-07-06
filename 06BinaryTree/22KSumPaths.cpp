void helper(Node* root,int& k, vector<int>vec,int &ans){
      vector<int>temp;
      temp.push_back(root->data);
      for(int i=0;i<vec.size();i++){
        temp.push_back(root->data+vec[i]);
      }
      for(int i=0;i<temp.size();i++){
          if(temp[i]==k)ans++;
      }
      if(root->left!=NULL)
      helper(root->left,k,temp,ans);
      if(root->right!=NULL)
      helper(root->right,k,temp,ans);
  }
    int sumK(Node *root,int k)
    {
        // code here
        if(root==NULL)return 0;
        int ans=0;
        vector<int>vec;
        helper(root,k,vec,ans);
        return ans;
    }