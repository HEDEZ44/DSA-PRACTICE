class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        string str = "";
        vector<int> chars(256, 0);
        vector<bool> vis(256, false);
        for (auto c : s)
        {
            chars[c]++;
        }
        for (auto c : s)
        {
            chars[c]--;
            if (vis[c])
                continue;
            while (!str.empty() && c < str.back() && chars[str.back()] != 0)
            {
                vis[str.back()] = false;
                str.pop_back();
            }
            str += c;
            vis[c] = true;
        }
        return str;
    }
};