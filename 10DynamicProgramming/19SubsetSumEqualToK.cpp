bool helper(int n,int sum,vector<int>&arr,vector<vector<int>>&dp){
    if(sum==0)return true;
    if(n==0)return arr[n]==sum;
    if(dp[n][sum]!=-1)return dp[n][sum];
    bool nt=helper(n-1,sum,arr,dp);
    bool t=false;
    if(arr[n]<=sum){
        t=helper(n-1,sum-arr[n],arr,dp);
    }
    return dp[n][sum]=t||nt;
}
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return helper(n-1,sum,arr,dp);
    }