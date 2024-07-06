 vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int>ans;
    	if(root==NULL)return ans;
    	queue<Node*>q;
    	q.push(root);
    	bool flag=1;
    	while(!q.empty()){
    	    int s=q.size();
    	    vector<int>sub;
    	    for(int i=0;i<s;i++){
    	        Node* node=q.front();
    	        q.pop();
    	        sub.push_back(node->data);
    	        if(node->left!=NULL){
    	            q.push(node->left);
    	        }
    	        if(node->right!=NULL){
    	            q.push(node->right);
    	        }
    	    }
    	        if(flag){
    	            for(int i=0;i<sub.size();i++){
    	                ans.push_back(sub[i]);
    	            }
    	        }else{
    	            for(int i=sub.size()-1;i>=0;i--){
    	                ans.push_back(sub[i]);
    	            }
    	        }
    	        flag=!flag;
    	}
    	return ans;
    }