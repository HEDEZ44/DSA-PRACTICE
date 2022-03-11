int mod = (int)(1e9 + 7);
int countPartitions(int n, int d, vector<int> &num)
{
    // Write your code here.
    int totalsum = 0;
    for (auto it : num)
        totalsum += it;
    if (totalsum - d < 0 || (totalsum - d) % 2 == 1)
        return 0;
    int tar = (totalsum - d) / 2;
    vector<int> prev(tar + 1, 0), curr(tar + 1, 0);
    if (num[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;
    if (num[0] != 0 && num[0] <= tar)
        prev[num[0]] = 1;
    for (int ind = 1; ind < n; ind++)
    {
        for (int sum = 0; sum <= tar; sum++)
        {
            int notTake = prev[sum];
            int take = 0;
            if (num[ind] <= sum)
                take = prev[sum - num[ind]];
            curr[sum] = (take + notTake) % mod;
        }
        prev = curr;
    }
    return prev[tar];
}
