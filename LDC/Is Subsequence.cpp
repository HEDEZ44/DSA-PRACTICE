class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        int i, j;
        for (i = 0, j = 0; i < n && j < m;)
        {
            if (s[j] == t[i])
            {
                i++;
                j++;
            }
            else
                i++;
        }
        if (j == m)
            return true;
        return false;
    }
};