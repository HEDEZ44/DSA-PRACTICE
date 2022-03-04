int uniquePaths(int m, int n)
{
    // Write your code here.
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 and j == 0)
                temp[j] = 1;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = temp[j - 1];
                temp[j] = up + left;
            }
        }
        prev = temp;
    }
    return prev[n - 1];
}

// O(1) space complexity

int uniquePaths(int m, int n)
{
    // Write your code here.
    int N = m + n - 2;
    int r = m - 1;
    double res = 1;
    for (int i = 1; i <= r; i++)
    {
        res = res * (N - r + i) / i;
    }
    return (int)res;
}