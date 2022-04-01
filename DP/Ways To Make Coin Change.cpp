#include <bits/stdc++.h>
long countWaysToMakeChange(int *nums, int n, int value)
{
    // Write your code here

    vector<long> prev(value + 1, 0), curr(value + 1, 0);
    for (int T = 0; T <= value; T++)
    {
        if (T % nums[0] == 0)
            prev[T] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int T = 0; T <= value; T++)
        {
            long notTake = prev[T];
            long take = 0;
            if (nums[i] <= T)
                take = curr[T - nums[i]];
            curr[T] = take + notTake;
        }
        prev = curr;
    }
    return prev[value];
}