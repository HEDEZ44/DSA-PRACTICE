#include <bits/stdc++.h>
int getMaxPathSum(vector<vector<int>> &mat)
{
    //  Write your code here.
    int n = mat.size();
    int m = mat[0].size();
    vector<int> prev(m, 0), curr(m, 0);
    for (int j = 0; j < m; j++)
        prev[j] = mat[0][j];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = prev[j] + mat[i][j];
            int ld = mat[i][j];
            if (j - 1 >= 0)
                ld += prev[j - 1];
            else
                ld = -1e8;
            int rd = mat[i][j];
            if (j + 1 < m)
                rd += prev[j + 1];
            else
                rd = -1e8;

            curr[j] = max(up, max(ld, rd));
        }
        prev = curr;
    }
    return *max_element(prev.begin(), prev.end());
}