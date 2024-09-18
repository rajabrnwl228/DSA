vector<long long> leftSmaller(int n, long long a[]){
        // code here
        stack<long long>st;
        st.push(-1);
        vector<long long>ans;
        for(int i=0;i<n;i++){
            while(st.top()!=-1&&a[st.top()]>=a[i]){
                st.pop();
            }
            ans.push_back(st.top());
            st.push(i);
        }
        return ans;
    }
    vector<long long> rightSmaller(int n, long long a[]){
        // code here
        stack<long long>st;
        st.push(-1);
        vector<long long>ans(n);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1&&a[st.top()]>=a[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long>prev=leftSmaller(n,arr);
        vector<long long>next=rightSmaller(n,arr);
        long long area=0;
        for(int i=0;i<n;i++){
            if(next[i]==-1){
                next[i]=n;
            }
            long long w=next[i]-prev[i]-1;
            long long newarea=arr[i]*w;
            area=max(area,newarea);
        }
        return area;
        
    }