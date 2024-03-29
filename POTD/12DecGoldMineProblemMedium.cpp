int maxGold(int n, int m, vector<vector<int>> M)
{
    // code here
    vector<vector<int>> arr(n, vector<int>(m, 0));
    int dr[3] = {-1, 0, 1};
    for (int i = 0; i < n; i++)
    {
        arr[i][m - 1] = M[i][m - 1];
    }
    for (int j = m - 2; j >= 0; j--)
    {
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < 3; k++)
            {
                int nr = i + dr[k];
                int nc = j + 1;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m)
                {
                    arr[i][j] = max(arr[i][j], arr[nr][nc]);
                }
            }
            arr[i][j] += M[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, arr[i][0]);
    }
    return ans;
}