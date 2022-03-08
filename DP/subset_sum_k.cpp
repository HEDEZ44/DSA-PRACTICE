bool f(int idx, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (idx == 0)
        return (arr[0] == target);
    if (dp[idx][target] != -1)
        return dp[idx][target];

    bool notTake = f(idx - 1, target, arr, dp);
    bool take = false;
    if (arr[idx] <= target)
        take = f(idx - 1, target - arr[idx], arr, dp);
    return dp[idx][target] = take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTake = dp[i - 1][target];
            bool take = false;
            if (arr[i] <= target)
                take = dp[i - 1][target - arr[i]];
            dp[i][target] = take || notTake;
        }
    }
    return dp[n - 1][k];
}