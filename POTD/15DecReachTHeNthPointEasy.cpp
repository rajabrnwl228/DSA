int nthPoint(int n)
{
    // Code here
    int a = 1, b = 2, c = 0;
    long long m = 1000000007;
    while (--n)
    {
        c = (a + b) % m;
        a = b;
        b = c;
    }
    return a;
}