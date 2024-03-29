char nthCharacter(string s, int r, int n) {
        //code here

        string y=s;
        for(int j=1;j<=r;j++){
            string x="";
            for(int i=0;i<s.size();i++){
                if(y[i]=='0')
                    x+="01";
                else
                    x+="10";
            }
            y=x;
        }
        return y[n];
    }