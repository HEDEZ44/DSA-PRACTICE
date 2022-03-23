class Solution
{
public:
    int brokenCalc(int sv, int target)
    {
        int ans = 0;
        while (target != sv)
        {
            if (target % 2 == 1 || target < sv)
                target += 1;
            else
                target /= 2;
            ans++;
        }
        return ans;
    }
};