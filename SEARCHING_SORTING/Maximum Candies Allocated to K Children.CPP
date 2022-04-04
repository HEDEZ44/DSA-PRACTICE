class Solution
{
public:
    bool solve(vector<int> &nums, long long mid, long long k)
    {
        long long cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            cnt += nums[i] / mid;
        }
        return cnt >= k;
    }
    int maximumCandies(vector<int> &candies, long long k)
    {
        int n = candies.size();
        int mx = *max_element(candies.begin(), candies.end());
        long long low = 1, high = mx;
        long long mid, ans = 0;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (solve(candies, mid, k))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};