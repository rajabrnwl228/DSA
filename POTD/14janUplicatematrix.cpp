vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N)
{
    // Your code here
    vector<int> ans;
    set<string> s;
    for (int i = 0; i < M; i++)
    {
        string a = "";
        for (int j = 0; j < N; j++)
        {
            a += to_string(matrix[i][j]);
        }
        if (s.find(a) != s.end())
        {
            ans.push_back(i);
        }
        else
        {
            s.insert(a);
        }
    }
    return ans;
}