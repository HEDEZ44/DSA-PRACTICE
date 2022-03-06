class Solution
{
public:
    vector<int> replaceNonCoprimes(vector<int> &nums)
    {
        vector<int> ans;
        for (auto a : nums)
        {
            while (true)
            {
                int x = __gcd(ans.empty() ? 1 : ans.back(), a);
                if (x == 1)
                    break;
                a *= ans.back() / x;
                ans.pop_back();
            }
            ans.push_back(a);
        }
        return ans;
    }
};