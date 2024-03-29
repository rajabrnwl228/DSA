 vector<int> Series(int n) {
        // Code here
        long long m=1e9+7;
        vector<int>ans(n+1,0);
        ans[1]=1;
        int c=2;
        while(c<=n){
           ans[c]=(ans[c-1]+ans[c-2])%m;
            c++;
        }
        return ans;
    }