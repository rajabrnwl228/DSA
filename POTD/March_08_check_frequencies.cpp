bool sameFreq(string s)
{
    // code here
    int size = s.size();
    vector<int> map(26, 0);
    for (int i = 0; i < size; i++)
    {
        int ele = s[i] - 'a';
        map[ele]++;
    }
    sort(map.begin(), map.end());
    int i = 25;
    if (map[i - 1] != map[i])
    {
        int maxi = map[i] - 1;
        for (int i = 24; i >= 0; i--)
        {
            if (map[i] == 0)
                continue;
            if (map[i] != maxi)
                return false;
        }
        return true;
    }
    else
    {
        int maxi = map[i];
        while (i > 0 && map[i] == maxi)
        {
            i--;
        }
        if (map[i] == 1 && map[i - 1] == 0 || map[i] == 0)
            return true;
        return false;
    }
}