#include <bits/stdc++.h>
using namespace std;
// Time Complexity O(2^n)  //(2*(1+2+4+8+16+32....+2^n=>2^(n+2)))
void MinimumDeveloper(vector<int> maskPeople, int i, int nskill, int smask, vector<int> onesol, vector<int> &sol)
{
    if (i == nskill)
    {
        if (smask == (1 << nskill) - 1)
        {
            if (sol.size() == 0 || onesol.size() < sol.size())
            {
                sol = onesol;
            }
        }
        return;
    }

    MinimumDeveloper(maskPeople, i + 1, nskill, smask, onesol, sol);
    onesol.push_back(i);
    MinimumDeveloper(maskPeople, i + 1, nskill, smask | maskPeople[i], onesol, sol);
    onesol.pop_back();
}
int main()
{
    // input skills
    int nskills;
    cout << "Enter Number of skills :\n";
    cin >> nskills;
    vector<string> skills;
    string s;
    for (int i = 0; i < nskills; i++)
    {
        cin >> s;
        skills.push_back(s);
    }
    // input people skills
    int n;
    cout << "Enter Number of people :\n";
    cin >> n;
    vector<string> people[n];
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Enter number of skill of person " << i + 1 << endl;
        cin >> x;
        while (x--)
        {
            string s;
            cin >> s;
            people[i].push_back(s);
        }
    }

    // create map/mask of skills
    unordered_map<string, int> map;
    for (int i = 0; i < nskills; i++)
    {
        map[skills[i]] = (1 << (nskills - i - 1));
    }
    // create mask of people
    vector<int> maskPeople(n);
    for (int i = 0; i < n; i++)
    {
        int mask = 0;
        for (int j = 0; j < people[i].size(); j++)
        {
            mask ^= map[people[i][j]];
        }
        maskPeople[i] = mask;
    }
    vector<int> onesol;
    vector<int> ans;
    MinimumDeveloper(maskPeople, 0, nskills, 0, onesol, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}