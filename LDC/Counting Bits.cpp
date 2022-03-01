class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> v;
        for (int i = 0; i <= n; i++)
        {

            v.push_back(__builtin_popcount(i));
        }
        return v;
    }
};

// built in function for counting bits is "__builtin_popcount"