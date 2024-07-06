int minTime(Node* root, int target) 
    {
        // Your code goes here
        if(root==NULL)return 0;
        //mapping
        Node* targetNode=NULL;
        queue<Node*>q;
        map<Node*,Node*>nodeToParent;
        q.push(root);
        nodeToParent[root]=NULL;
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            if(temp->data==target)targetNode=temp;
            if(temp->left!=NULL){
                nodeToParent[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                nodeToParent[temp->right]=temp;
                q.push(temp->right);
            }
        }
        
        //burn tree
        queue<Node*>qb;
        map<Node*,int>vis;
        qb.push(targetNode);
        vis[targetNode]=1;
        int timer=0;
        while(!qb.empty()){
            timer++;
            int s=qb.size();
            for(int i=0;i<s;i++){
                Node* temp=qb.front();
                qb.pop();
                if(nodeToParent[temp]&& vis[nodeToParent[temp]]!=1){
                    qb.push(nodeToParent[temp]);
                    vis[nodeToParent[temp]]=1;
                }
                if(temp->left!=NULL&&vis[temp->left]!=1){
                    qb.push(temp->left);
                    vis[temp->left]=1;
                }
                if(temp->right!=NULL&&vis[temp->right]!=1){
                    vis[temp->right]=1;
                    qb.push(temp->right);
                }
            }
        }
        return timer-1;
    }