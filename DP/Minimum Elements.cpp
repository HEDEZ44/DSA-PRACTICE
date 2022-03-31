int f(int ind, int T, vector<int> &nums)
{
    if (ind == 0)
    {
        if (T % nums[0] == 0)
            return T / nums[0];
        return 1e9;
    }

    int notTake = f(ind - 1, T, nums);
    int take = INT_MAX;
    if (nums[ind] <= T)
        take = 1 + f(ind, T - nums[ind], nums);

    return min(take, notTake);
}

int minimumElements(vector<int> &nums, int x)
{
    // Write your code here.
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    vector<int> prev(x + 1, 0), curr(x + 1, 0);
    for (int T = 0; T <= x; T++)
    {
        if (T % nums[0] == 0)
            prev[T] = T / nums[0];
        else
            prev[T] = 1e9;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int T = 0; T <= x; T++)
        {
            int notTake = prev[T];
            int take = INT_MAX;
            if (nums[ind] <= T)
            {
                take = 1 + curr[T - nums[ind]];
            }
            curr[T] = min(take, notTake);
        }
        prev = curr;
    }
    return prev[x] >= 1e9 ? -1 : prev[x];
}