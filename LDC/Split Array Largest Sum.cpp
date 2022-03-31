class Solution
{
public:
    bool isPossible(vector<int> &nums, int mid, int m)
    {
        int sa = 1;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > mid)
            {
                sa++;
                sum = nums[i];
            }
        }
        return sa <= m;
    }
    int splitArray(vector<int> &nums, int m)
    {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int lo = mx;
        int hi = sum;
        int ans = 0;
        if (n == m)
            return mx;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (isPossible(nums, mid, m))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return lo;
    }
};