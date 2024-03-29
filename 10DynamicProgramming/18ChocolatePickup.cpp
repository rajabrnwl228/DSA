//memoization
int helper(int r, int c1,int c2, int R,int C, vector<vector<int>> &grid,vector<vector<vector<int>>>&dp){
    if(c1<0||c1>=C||c2<0||c2>=C)return -1e8;
    if(r==R-1){
        if(c1==c2)return grid[r][c1];
        else return grid[r][c1]+grid[r][c2];
    }
    if(dp[r][c1][c2]!=-1)return dp[r][c1][c2];
    int ans=-1e8;
    for(int j1=-1;j1<=1;j1++){
        for(int j2=-1;j2<=1;j2++){
            int val=0;
            if(c1==c2)val= grid[r][c1];
            else val=grid[r][c1]+grid[r][c2];
            val+=helper(r+1,c1+j1,c2+j2,R,C,grid,dp);
            ans=max(ans,val);
        }
    }   
    return dp[r][c1][c2]=ans;
}
    int solve(int r, int c, vector<vector<int>>& grid) {
        // code here
     vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return helper(0,0,c-1, r,c,grid,dp);
        
    }


    //tabular
         int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
         vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2)dp[n-1][j1][j2]=grid[n-1][j1];
            else dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                int maxi=-1e8;
                for(int dj1=-1;dj1<=1;dj1++){
                    for(int dj2=-1;dj2<=1;dj2++){
                        int val=0;
                        if(j1==j2)val=grid[i][j1];
                        else val=grid[i][j1]+grid[i][j2];
                        if(j1+dj1>=0&&j2+dj2>=0&&j1+dj1<m&&j2+dj2<m)
                            val+=dp[i+1][j1+dj1][j2+dj2];
                        else 
                        val+=-1e8;
                        maxi=max(maxi,val);

                    }
                }
                    dp[i][j1][j2]=maxi;
            }
        }
    }
    return dp[0][0][m-1];
        
    }