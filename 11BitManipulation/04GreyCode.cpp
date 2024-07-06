#include <bits/stdc++.h>
using namespace std;
// Time Complexity O(2^n)  //(2*(1+2+4+8+16+32....+2^n=>2^(n+2)))
vector<string> GrayCode(int n)
{
    if (n == 1)
    {
        vector<string> base;
        base.push_back("0");
        base.push_back("1");
        return base;
    }
    vector<string> base = GrayCode(n - 1);
    vector<string> res;
    // Time Complexity O(2^n)

    for (int i = 0; i < base.size(); i++)
    {
        res.push_back("0" + base[i]);
    }
    // Time Complexity O(2^n)
    for (int i = base.size() - 1; i >= 0; i--)
    {
        res.push_back("1" + base[i]);
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<string> ans = GrayCode(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}