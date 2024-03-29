// Using recursion
//time complexity 2^(m+n)
//space complexityO(m+n) (stack)
int recursion(int i,int j,int m,int n){
	if(i==m&&j==n)return 1;
	if(i>m||j>n)return 0;
	int r=recursion(i,j+1,m,n);
	int b=recursion(i+1,j,m,n);
	return r+b;
}
int uniquePaths(int m, int n) {
	// Write your code here.
	return recursion(0,0,m-1,n-1);
}
// Using memoization
//time complexity O(m*n)
//space complexity O(m+n)-stack + O(m*n)

int recursion(int i,int j,vector<vector<int>>&dp){
	if(i==0&&j==0)return 1;
	if(i<0||j<0)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	int l=recursion(i,j-1,dp);
	int t=recursion(i-1,j,dp);
	return dp[i][j]=l+t;
}
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>>dp(m,vector<int>(n,-1));
	return recursion(m-1,n-1,dp);
}

//tabular
//time complexity O(m*n)
//space complexity O(m*n)

int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>>dp(m,vector<int>(n,1));
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){			
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	return dp[m-1][n-1];

}
// another way of tabular
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>>dp(m,vector<int>(n,0));
	dp[0][0]=1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			int l=0,t=0;
			if(j>0)
			l=dp[i][j-1];
			if(i>0)
			t=dp[i-1][j];
			dp[i][j]=max(dp[i][j],t+l);
		}
	}
	return dp[m-1][n-1];

}
// space optimization
//time complexity O(m*n)
//space complexity O(n)
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<int>prev(n,1);
	for(int i=1;i<m;i++){
		vector<int>temp(n,1);
		int left=1;
		for(int j=1;j<n;j++){			
			temp[j]=prev[j]+temp[j-1];
		}
		prev=temp;
	}
	return prev[n-1]; 

}