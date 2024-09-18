vector<long long> rightSmaller(int n, long long a[]){
        // code here
        stack<long long>st;
        st.push(-1);
        vector<long long>ans;
        for(int i=n-1;i>=0;i--){
            while(st.top()>=a[i]){
                st.pop();
            }
            ans.push_back(st.top());
            st.push(a[i]);
        }
        return ans;
    }