static bool com(string &a, string &b)
{
    string s1 = a + b;
    string s2 = b + a;
    return s1 > s2;
}
string printLargest(int n, vector<string> &arr)
{

    sort(arr.begin(), arr.end(), com);
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        ans = ans + arr[i];
    }
    return ans;
}