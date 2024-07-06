#include <bits/stdc++.h>
using namespace std;
void kernighanAlgo(int n)
{
    int count = 0;
    // Time Complexity O(32)=O(1)
    while (n != 0)
    {
        int t = n & (-n);
        n -= t;
        count++;
    }
    cout << count << endl;
}
int main()
{
    int n;
    cout << "Enter the Number: ";
    cin >> n;
    int rmsb = n & (-n);
    cout << rmsb << endl;
    bitset<8> b(rmsb);
    cout << b << endl;
    // 1nd Method
    kernighanAlgo(n);
    // 2nd Method
    bitset<8> b1(n);
    cout << b1.count() << endl;
    return 0;
}