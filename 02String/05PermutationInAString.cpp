bool checkwindow(int cnt1[],int cnt2[]){
    for(int i=0;i<26;i++){
        if(cnt1[i]!=cnt2[i])return 0;
    }
    return 1;
}
    bool checkInclusion(string s1, string s2) {
        int cnt1[26],cnt2[26];
        for(int i=0;i<26;i++){
            cnt1[i]=0;
            cnt2[i]=0;
        }
        int m=s1.size();
        int n= s2.size();
        if(n<m)    return false;
        for(int i=0;i<m;i++){                   
            cnt1[s1[i]-'a']++;
        }
        int j=0;
        for(;j<m;j++) {
            cnt2[s2[j]-'a']++;
        }
        //check window  
        if(checkwindow(cnt1,cnt2))return true;
        //sliding window
        while(j<n){
            cnt2[s2[j-m]-'a']--;
            cnt2[s2[j]-'a']++;
            if(checkwindow(cnt1,cnt2))return true;
            j++;
        }
        return false;
        
         
    }