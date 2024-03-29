queue<int> modifyQueue(queue<int> q, int k)
{
    // add code here.
    stack<int> st;
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }
    int n = q.size();
    for (int i = 0; i < k; i++)
    {
        q.push(st.top());
        st.pop();
    }
    for (int i = 0; i < n; i++)
    {
        int a = q.front();
        q.pop();
        q.push(a);
    }
    return q;
}