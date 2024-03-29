long maximumSumSubarray(int K, vector<int> &Arr, int N)
{
    // code here
    long long sum = 0, ans = 0;
    int i = 0;
    for (; i < K; i++)
    {
        sum += Arr[i];
    }
    ans = sum;
    for (; i < N; i++)
    {
        sum += Arr[i];
        sum -= Arr[i - K];
        ans = max(ans, sum);
    }
    return ans;
}