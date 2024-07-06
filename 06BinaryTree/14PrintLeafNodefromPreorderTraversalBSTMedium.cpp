vector<int> leafNodes(int arr[], int N)
{
    // code here
    vector<int> ans;
    stack<int> s;
    s.push(arr[0]);
    for (int i = 1; i < N; i++)
    {
        if (arr[i] < s.top())
            s.push(arr[i]);
        else
        {
            int t = s.top();
            int rem = 0;
            while (s.size() > 0 && s.top() < arr[i])
            {
                s.pop();
                rem++;
            }
            s.push(arr[i]);
            if (rem >= 2)
                ans.push_back(t);
        }
    }
    ans.push_back(arr[N - 1]);
    return ans;
}