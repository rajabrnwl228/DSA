    int firstElementKTime(int n, int k, int a[])
    {
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp.find(a[i])!=mp.end()){
                if(mp[a[i]]==k-1)return a[i];
            }
                mp[a[i]]++;
        }
        return -1;
        
    }