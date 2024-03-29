
// memoization
#include <bits/stdc++.h>
int helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
  if(i==0&&j==0)return dp[i][j]=grid[i][j];
if(dp[i][j]!=-1)return dp[i][j];
int l=grid[i][j];
int t=grid[i][j];
if(i>0)t+=helper(i-1,j,grid,dp);
else t+=1e9;
if(j>0)l+=helper(i,j-1,grid,dp);
else l+=1e9;
return dp[i][j]=min(t,l);
}
int minSumPath(vector<vector<int>> &grid) {
    int m=grid.size(),n=grid[0].size();
   vector<vector<int>>dp(m,vector<int>(n,-1));
    helper(m-1,n-1,grid,dp);
    return dp[m-1][n-1];

}

// tabular
int minSumPath(vector<vector<int>> &grid) {
    int m=grid.size(),n=grid[0].size();
   vector<vector<int>>dp(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0&&j==0)dp[i][j]=grid[i][j];
            else {
              int left =0,top=0;
              if(i>0)
                top = dp[i-1][j];
              else
                top = 1e9;
              if (j > 0)
                left = dp[i][j - 1];
              else left=1e9;
              dp[i][j] = grid[i][j] + min(top, left);
            }
        }
    }
    return dp[m-1][n-1];

} 
//  space optimization
 
 int minSumPath(vector<vector<int>> &grid) {
 int m=grid.size(),n=grid[0].size();
    vector<int>prevRow(n,0);
    for(int i=0;i<m;i++){
        vector<int>temp(n,0);
        for(int j=0;j<n;j++){
            if(i==0&&j==0)temp[j]=grid[i][j];
            else {9
              int left =0,top=0;
              if(i>0)
                top = prevRow[j];
              else
                top = 1e9;
              if (j > 0)
                left = temp[j - 1];
              else left=1e9;
              temp[j] = grid[i][j] + min(top, left);
            }
        }
        prevRow=temp;
        // cout<<endl;
    }
   