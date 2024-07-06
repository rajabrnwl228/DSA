#include <bits/stdc++.h>
using namespace std;
int powerCloset(int n)
{
    int i = 1;
    // Time Complexity O(logn)
    while (2 * i <= n)
    {
        i = 2 * i;
    }
    return i;
}
int main()
{
    int n;
    cin >> n;
    int x = powerCloset(n);
    int l = n - x;
    cout << 2 * l + 1 << endl;
    return 0;
}