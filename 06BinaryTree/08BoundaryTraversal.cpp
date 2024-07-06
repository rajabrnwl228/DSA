void leftboundary(Node*root,vector<int>&ans){
        if(root==NULL||(root->left==NULL&&root->right==NULL))
        return ;
        ans.push_back(root->data);
        if(root->left!=NULL)
            leftboundary(root->left,ans);
        else
            leftboundary(root->right,ans);
    }
    void rightboundary(Node*root,vector<int>&ans){
        if(root==NULL||(root->left==NULL&&root->right==NULL))
        return ;
          
        if(root->right!=NULL)
            rightboundary(root->right,ans);
        else
         rightboundary(root->left,ans);
         
          ans.push_back(root->data);
    }
    void leafboundary(Node*root,vector<int>&ans){
         if(root==NULL)
        return ;
        if(root->left==NULL &&root->right==NULL)
        {   
            ans.push_back(root->data);
            return ;
        }
        
        leafboundary(root->left,ans);
        leafboundary(root->right,ans);
    }
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(root==NULL)
        return ans;
        ans.push_back(root->data);
        leftboundary(root->left,ans);
        leafboundary(root->left,ans);
        leafboundary(root->right,ans);
        rightboundary(root->right,ans);
       return ans;
        //Your code here
    }