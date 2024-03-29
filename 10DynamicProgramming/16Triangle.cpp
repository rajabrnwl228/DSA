// memoization
int helper(vector<vector<int>>& triangle, int i,int j, int n,vector<vector<int>>& dp){
if(i==n-1)return triangle[i][j];
if(dp[i][j]!=-1)return dp[i][j];
int b=triangle[i][j]+helper(triangle,i+1,j,n,dp);
int d=triangle[i][j]+helper(triangle,i+1,j+1,n,dp);
return dp[i][j]=min(d,b);
}
int minimumPathelperSum(vector<vector<int>>& triangle, int n){
	// Write your code help
	vector<vector<int>>dp(n,vector<int>(n,-1));
	return helper(triangle,0,0,n,dp);
}
//tabular
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<vector<int>>dp(n,vector<int>(n,0));
	dp[0][0]=triangle[0][0];
	for(int i=1;i<n;i++){
		for(int j=0;j<=i;j++){
			int t=triangle[i][j];
			if(j<i)
			t+=dp[i-1][j];
			else t+=1e9;
			int d=triangle[i][j];
			if(j>0)
			d+=dp[i-1][j-1];
			else d+=1e9;
			dp[i][j]=min(t,d);
		}
	}
int ans=1e9;
for(int i=0;i<n;i++)
{
	ans=min(ans,dp[n-1][i]);
}
	return ans;

}


//space opotimization
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<int>botRow(n,0);
	vector<int>temp(n,0);
	for(int i=0;i<n;i++)
		botRow[i]=triangle[n-1][i];
	for(int i=n-2;i>=0;i--){
		for(int j=i;j>=0;j--){
			int b=triangle[i][j]+botRow[j];
			int dg=triangle[i][j]+botRow[j+1];
			temp[j]=min(b,dg);
		}
		botRow=temp;
	}
	return botRow[0];
}