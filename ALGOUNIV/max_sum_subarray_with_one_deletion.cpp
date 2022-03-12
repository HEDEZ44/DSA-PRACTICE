class Solution
{
public:
    int maximumSum(vector<int> &arr)
    {
        int n = arr.size(), mx = INT_MIN;
        vector<vector<int>> dp(n + 1, vector<int>(2, -1e9)); // Initially initialize with -infinity
        /* dp[i][0] represents the maximum sum at position i with 0 deletions
           dp[i][1] represents the maximum sum at position i with 1 deletions
           Notice that dp is subscripted from 1 to n hence we take arr[i-1] in the for loop
        */
        for (int i = 1; i <= n; ++i)
        {
            dp[i][0] = max(dp[i - 1][0] + arr[i - 1], arr[i - 1]);   // If there is no deletion the max sum at postion i is equal to max of the maximum sum at positon i - 1 or starting a new sum at position i
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i - 1]); // If there is 1 deletion we have 2 choices either delete the element at position i or not delete the element at position i. If we delete the element at position i , dp[i][1] = dp[i-1][0] . If we don't delete the element at position i we add the value of the element at position i , therefore , dp[i][1] = dp[i-1][1] + arr[i-1]
            mx = max({mx, dp[i][0], dp[i][1]});                      // The maximum answer can also be obtained without deleting any element
        }
        return mx;
    }
};