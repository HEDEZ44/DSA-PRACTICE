#include <bits/stdc++.h>
int minSubsetSumDifference(vector<int> &arr, int n)
{
    // Write your code here.
    int k = 0;
    for (int i = 0; i < n; i++)
        k += arr[i];
    vector<bool> prev(k + 1, false);
    prev[0] = true;
    prev[arr[0]] = true;
    vector<bool> curr(k + 1, false);
    curr[0] = true;
    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTake = prev[target];
            bool take = false;
            if (arr[i] <= target)
                take = prev[target - arr[i]];
            curr[target] = take || notTake;
        }
        prev = curr;
    }
    int ans = INT_MAX;
    for (int i = 0; i < k + 1; i++)
    {
        if (prev[i])
        {
            int s1 = i;
            int s2 = k - i;
            ans = min(ans, abs(s1 - s2));
        }
    }
    return ans;
}
