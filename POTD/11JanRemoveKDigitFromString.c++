string removeKdigits(string S, int K)
{
    stack<char> st;
    int i = 0, n = S.size();
    while (i < n)
    {
        while (st.size() > 0 && K > 0 && S[i] < st.top())
        {
            st.pop();
            K--;
        }
        st.push(S[i]);
        i++;
    }
    string ans = "";
    // edge case
    if (st.size() == 0)
        return "0";
    while (K > 0)
    {
        st.pop();
        K--;
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    i = 0;
    while (ans[i] == '0')
    {
        i++;
    }
    if (i == ans.size())
        return "0";
    return ans.substr(i);
}