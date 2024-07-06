#include <bits/stdc++.h>
using namespace std;
// Time Complexity O(1)
int main()
{
    int n;
    cin >> n;
    int rmsb = n & (-n);
    cout << rmsb << endl;
    bitset<8> b(rmsb);
    cout << b << endl;
    return 0;
}