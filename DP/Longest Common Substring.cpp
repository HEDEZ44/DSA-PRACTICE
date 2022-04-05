int lcs(string &str1, string &str2)
{
    //	Write your code here.
    int m = str2.length();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    int n = str1.length();

    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
                mx = max(mx, curr[j]);
            }
            else
                curr[j] = 0;
        }
        prev = curr;
    }
    return mx;
}