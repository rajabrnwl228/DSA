/* NUMBER OF PATHS
To count all the possible paths from top left to bottom right of an M*N matrix with the constrainst that from each cell you either move to right or down
return answer modulo 10^9+7

Example 1:

Input:
M = 3 and N = 3
Output: 6
Explanation:
Let the given input 3*3 matrix is filled
as such:
A B C
D E F
G H I
The possible paths which exists to reach
'I' from 'A' following above conditions
are as follows:ABCFI, ABEHI, ADGHI, ADEFI,
ADEHI, ABEFI
Expected Time Complexity: O(M)
Expected Space Complexity: O(1)
*/

long long mod = 1000000007;
long long invert(long long i)
{
    long long ans = 1;
    int m = mod - 2;
    while (m > 0)
    {
        if (m & 1 != 0)
            ans = (ans * i) % mod;
        i = (i * i) % mod;
        m = m >> 1;
    }
    return ans;
}
long long per(int N, int M)
{
    long long ans = 1;
    for (int i = 1; i <= M; i++)
    {
        long long a = (N + i);
        ans = (ans * a) % mod;
        long long divi = invert(i);
        ans = (ans * divi) % mod;
    }
    return ans;
}
long long numberOfPaths(int M, int N)
{
    // Code Here
    M = M - 1;
    N = N - 1;
    long long y = min(M, N);
    long long x = max(M, N);
    long long ans = per(x, y);
    return ans;
}