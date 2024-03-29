vector<int> search(string pattern, string text)
{
    // code here.
    vector<int> r;
    int ts = text.size();
    int ps = pattern.size();
    for (int i = 0; i < ts - ps; i++)
    {
        string t = text.substr(i, ps);
        if (t == pattern)
            r.push_back(i + 1);
    }
    return r;
}