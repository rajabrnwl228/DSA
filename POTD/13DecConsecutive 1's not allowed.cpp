ll countStrings(int n)
{
    // code here
    long long mod = 1000000007;
    int k = n - 1;
    long long a = 1;
    long long b = 2, c = 0;
    while (k--)
    {
        c = (a + b) % mod;
        a = b;
        b = c;
    }
    return b;
}