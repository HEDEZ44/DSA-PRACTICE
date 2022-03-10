int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<int> prev(tar + 1, 0), curr(tar + 1);
    prev[0] = curr[0] = 1;
    if (num[0] <= tar)
        prev[num[0]] = 1;

    for (int ind = 1; ind < n; ind++)
    {
        for (int sum = 0; sum <= tar; sum++)
        {
            int notTake = prev[sum];
            int take = 0;
            if (num[ind] <= sum)
                take = prev[sum - num[ind]];
            curr[sum] = take + notTake;
        }
        prev = curr;
    }
    return prev[tar];
}