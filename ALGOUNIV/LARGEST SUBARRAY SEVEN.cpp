#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    long long sum = 0;
    vector<int> mod(n, 0);
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        mod[i] = sum % 7;
    }
    unordered_map<int, int> mp;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (mod[i] == 0)
            max = i + 1;
        else if (mp.find(mod[i]) == mp.end())
            mp[mod[i]] = i;
        else
        {
            if (max < i - mp[mod[i]])
                max = i - mp[mod[i]];
        }
    }
    cout << max;
    return 0;
}