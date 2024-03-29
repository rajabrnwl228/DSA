//memoization
int helper(int i,int j, int N,vector<vector<int>>&Matrix,vector<vector<int>>&dp){
    if(i>=N||j<0||j>=N){
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int dw=Matrix[i][j]+helper(i+1,j,N,Matrix,dp);
    int dl=Matrix[i][j]+helper(i+1,j-1,N,Matrix,dp);
    int dr=Matrix[i][j]+helper(i+1,j+1,N,Matrix,dp);
    return dp[i][j]=max(dw,max(dl,dr));
    
}
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(N,-1));
        int ans=0;
        for(int i=0;i<N;i++){
            ans=max(ans,helper(0,i,N,Matrix,dp));
        }
        return ans;
        
    }

    // bottom up tabular
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(N,0));
        for(int i=0;i<N;i++)dp[N-1][i]=Matrix[N-1][i];
        for(int i=N-2;i>=0;i--){
            for(int j=0;j<N;j++){
                int dw=dp[i+1][j];
                int dr=0,dl=0;
                if(j>0)
                dl=dp[i+1][j-1];
                else 
                dl=-1e8;
                if(j<N-1)
                dr=dp[i+1][j+1];
                else 
                dr=-1e8;
                dp[i][j]=Matrix[i][j]+max(dw,max(dl,dr));
            }
        }
        int ans=-1e8;
        for(int i=0;i<N;i++)  ans=max(ans,dp[0][i]);
        return ans;
        
    }

    //top down tabular
     int maximumPath(int N, vector<vector<int>> matrix)
    {
        // code here
      int m=N,n=N;
    vector<vector<int>>dp(m,vector<int>(n,0));
    for (int j = 0; j < n; j++) {
        dp[0][j]=matrix[0][j];
    }
    for(int i=1;i<m;i++){
        for(int j=0;j<n;j++){
            int top=matrix[i][j]+dp[i-1][j];
            int ld=matrix[i][j],rd=matrix[i][j];
            if(j>0)
            ld+=dp[i-1][j-1];
            else
            ld+=-1e8;
            if(j<n-1)
            rd+=dp[i-1][j+1];
            else
            rd+=-1e8;
            dp[i][j]=max(top,max(rd,ld));
        }
    }
    int ans=-1e8;
    
    for (int j = 0; j < n; j++) {
        ans = max(ans, dp[m - 1][j]);
    }
    return ans;
    }

    //space optimization
        int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        vector<int>prev(N,0);
        for(int i=0;i<N;i++)prev[i]=Matrix[N-1][i];
        for(int i=N-2;i>=0;i--){
            vector<int>temp(N,0);
            for(int j=0;j<N;j++){
                int dw=prev[j];
                int dr=0,dl=0;
                if(j>0)
                dl=prev[j-1];
                else 
                dl=-1e8;
                if(j<N-1)
                dr=prev[j+1];
                else 
                dr=-1e8;
                temp[j]=Matrix[i][j]+max(dw,max(dl,dr));
            }
            prev=temp;
        }
        int ans=-1e8;
        for(int i=0;i<N;i++)  ans=max(ans,prev[i]);
        return ans;
        
    }