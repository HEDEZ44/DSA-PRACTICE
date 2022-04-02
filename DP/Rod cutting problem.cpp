int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int N = 0; N <= n; N++)
        dp[0][N] = N * price[0];

    for (int i = 1; i < n; i++)
    {
        for (int N = 0; N <= n; N++)
        {
            int notTake = dp[i - 1][N];
            int take = INT_MIN;
            int rodLength = i + 1;
            if (rodLength <= N)
                take = price[i] + dp[i][N - rodLength];
            dp[i][N] = max(take, notTake);
        }
    }
    return dp[n - 1][n];
}
