 void InOrder(Node* root,vector<int>&arr){
        if(root==NULL)return ;
        InOrder(root->left,arr); 
        arr.push_back(root->data);
        InOrder(root->right,arr);
        
    }
    
    int merge(vector<int>&arr,int l,int mid,int h){
        vector<int>temp;
        int left=l;
        int right=mid+1;
        int ans=0;
        while(left<=mid&&right<=h){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                ans+=(mid-left+1);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
                left++;
        }
        while(right<=h){
            temp.push_back(arr[right]);
                right++;
        }
        for(int i=l;i<=h;i++)arr[i]=temp[i-l];
        return ans;
    }
    
    int mergeSort(vector<int>&arr,int l,int h){
        int ans=0;
        if(l>=h)return ans;
        int mid=l+(h-l)/2;
        ans+=mergeSort(arr,l,mid);
        ans+=mergeSort(arr,mid+1,h);
        ans+=merge(arr,l,mid,h);
        return ans;
    }
    
    
  public:

    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root) {
        // your code goes here
        vector<int>arr;
        InOrder(root,arr);
       return mergeSort(arr,0,n-1);
       
    }