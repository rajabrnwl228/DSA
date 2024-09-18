vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        if(n%2==1)return {};
        vector<int>ans;
        sort(changed.begin(),changed.end());
        unordered_map<int,int>mp;
        for(int i=n-1;i>=0;i--){
            int x=2*changed[i];
            if(mp[x]>0){
                ans.push_back(changed[i]);
                mp[x]--;
            }
            else{
                mp[changed[i]]++;
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==n/2)return ans;
        return {};
    }