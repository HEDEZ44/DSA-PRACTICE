class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        if (nums.size() < 3)
            return 0;

        int n = nums.size();
        int count = 0;
        int curr = 0;

        for (int i = 2; i < n; i++)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                curr++;
                count += curr;
            }
            else
                curr = 0;
        }
        return count;
    }
};