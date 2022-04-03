class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        set<int> s;
        map<int, int> mp;
        for (auto it : matches)
        {
            s.insert(it[0]);
            s.insert(it[1]);
            mp[it[1]]++;
        }
        vector<vector<int>> ans(2);
        for (auto &it : s)
        {
            if (mp[it] == 1)
            {
                ans[1].push_back(it);
            }
            else if (!mp[it])
            {
                ans[0].push_back(it);
            }
        }
        return ans;
    }
};