int compress(vector<char>& chars) {
        int st=0;
        int i=0,n=chars.size();
        while(i<n){
            int j=i+1;
            while(j<n&&chars[j]==chars[i]){
               j++; 
            }
            int cnt=j-i;
            chars[st++]=chars[i];
            if(cnt>1){
                string num=to_string(cnt);
                for(auto it:num){
                    chars[st++]=it;
                }
            }
            i=j;
        }
        return st;
    }