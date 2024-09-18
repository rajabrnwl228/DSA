 string sortSentence(string s) {
        int i=0,cnt=0,n=s.size();
        vector<string>v(9,"");
        string t="";
        while(i<n){
            int j=i;
            while(s[j]>=97&&s[j]<=122||s[j]>=65&&s[j]<=91){
                t=t+s[j];
                j++;
            }
            int n=s[j]-49;
            v[n]=t;
            cnt++;
            t.clear();
            i=j+2;
        }
        string ans="";
        for(int i=0;i<cnt;i++){
            ans+=v[i];
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }