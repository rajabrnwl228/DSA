long long countWays(int n, int k)
{
    // code here
    long long mod = 1000000007;
    long long dp[n + 1];
    dp[0] = 1;
    dp[1] = k;
    dp[2] = (k + (k % mod * (k - 1) % mod) % mod) % mod;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (((dp[i - 1] + dp[i - 2]) % mod) * ((k - 1) % mod)) % mod;
    }
    return dp[n];
}