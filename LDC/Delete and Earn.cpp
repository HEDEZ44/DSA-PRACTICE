class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {

        int n1 = *max_element(nums.begin(), nums.end());
        int n2 = *min_element(nums.begin(), nums.end());

        vector<int> freq(20000, 0);
        for (auto it : nums)
            freq[it]++;

        int inc = 0;
        int exe = 0;

        for (int i = n2; i <= n1; i++)
        {
            int ni = exe + freq[i] * i;
            int ne = max(exe, inc);
            inc = ni;
            exe = ne;
        }
        return max(inc, exe);
    }
};