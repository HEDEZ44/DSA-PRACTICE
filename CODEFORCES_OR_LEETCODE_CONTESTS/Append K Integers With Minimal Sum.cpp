class Solution
{
public:
    long long minimalKSum(vector<int> &nums, int k)
    {

        long long ans = (long long)k * (k + 1) / 2;
        int last = k + 1;
        set<int> num(nums.begin(), nums.end());
        for (auto it : num)
        {
            if (it < last)
            {
                ans += last - it;
                last++;
            }
        }
        return ans;
    }
};