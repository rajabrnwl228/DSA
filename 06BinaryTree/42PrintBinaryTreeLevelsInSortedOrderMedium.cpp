vector<vector<int>> binTreeSortedLevels(int arr[], int n)
{
    // Your code here
    vector<vector<int>> ans;
    int i = 0, j = 0, s = 0;
    while (i < n)
    {
        int t = pow(2, s);
        vector<int> subans;
        for (j = 0; j < t && i + j < n; j++)
        {
            subans.push_back(arr[i + j]);
        }
        sort(subans.begin(), subans.end());
        ans.push_back(subans);
        i = i + j;
        s++;
    }
    return ans;
}