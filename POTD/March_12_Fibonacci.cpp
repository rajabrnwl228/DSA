vector<vector<long long>> multiply(vector<vector<long long>>&x,vector<vector<long long>>&y,long long m){
     int sz=x.size();
    vector<vector<long long>>res2(sz,vector<long long>(sz,0));
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
          for (int k = 0; k < sz; k++) {
            res2[i][j] =(res2[i][j]+((x[i][k])%m * (y[k][j])%m))%m;
            // res2[i][j] =(res2[i][j]+((x[i][k]) * (y[k][j])));
          }
        }
    }

    return res2;
}
vector<vector<long long >> Exp( vector<vector<long long>>&d, long long n,long long m){
    
    if(n<=0){
        int sz=d.size();
        vector<vector<long long>>I(sz,vector<long long>(sz,0));
        for (int i = 0; i < sz; i++) {
          I[i][i] = 1;
        }
        return I;
    }
    if(n==1) return d;
    vector<vector<long long>>temp=Exp(d,n/2,m);
    vector<vector<long long>>ans=multiply(temp,temp,m);

    if(n&1)
    ans=multiply(ans,d,m);
    
    return ans;


}
    long long genFibNum(long long a, long long b, long long c, long long n, long long m) {
        // code here
        vector<vector<long long>>d(3,vector<long long>(3,0));
        d[0][0]=a;
        d[0][1]=b;
        d[0][2]=c;
        d[1][0]=1;
        d[2][2]=1;
     vector<vector<long long>>ans=Exp(d,n-2,m);
    //  for(int i=0;i<ans.size();i++){
    //     cout<<ans[i][0]<<"@"<<ans[i][1]<<"@"<<ans[i][2]<<endl;
    // }
        return (ans[0][0]+ans[0][1]+ans[0][2])%m;
        
    }