class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int i = n - 2;
        while (i >= 0)
        {
            if (nums[i] < nums[i + 1])
                break;
            i--;
        }
        if (i < 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        sort(nums.begin() + i + 1, nums.end());
        int it = upper_bound(nums.begin() + i + 1, nums.end(), nums[i]) - nums.begin();
        swap(nums[i], nums[it]);
    }
};