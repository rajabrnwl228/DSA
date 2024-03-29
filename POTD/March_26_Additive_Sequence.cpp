string sumfun(string a,string b){
       int i=a.size()-1,j=b.size()-1;
       int carry=0;
       string sum="";
       while(i>=0&&j>=0){
           int x=(a[i]-'0');
           int y=(b[j]-'0');
           int s=x+y+carry;
           sum+=((s%10)+'0');
           carry=s/10;
           i--;
           j--;
       }
       while(i>=0){
           int s=(a[i]-'0')+carry;
           sum+=((s%10)+'0');
           carry=s/10;
           i--;
       }
       while(j>=0){
           int s=(b[j]-'0')+carry;
           sum+=((s%10)+'0');
           carry=s/10;
           j--;
       }
       if(carry){
           sum+=(carry+'0');
       }
       reverse(sum.begin(),sum.end());
       return sum;
   }
    bool check(string a,string b,string c){
        string s=sumfun(a,b);
        int i=0,j=0;
        while(i<c.size()&&j<s.size()){
            if(c[i]!=s[j])return false;
            i++;j++;
        }
        if(j!=s.size())return false;
        if(i==c.size())return true;
        c=c.substr(i);
        return check(b,s,c);
    }
    bool isAdditiveSequence(string n) {
        // Your code here
        int size=n.size();
        for(int i=0;i<size/2;i++){
            for(int j=i+1;j<size-1;j++){
                string a=n.substr(0,i+1);
                string b=n.substr(i+1,j-i);
                string c=n.substr(j+1);
                if(check(a,b,c))return true;
            }
        }
        return false;
    }