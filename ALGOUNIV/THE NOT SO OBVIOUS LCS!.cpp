#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    unordered_map<int, int> mp;
    for (int i = 0; i < m; i++)
        mp[b[i]] = i;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        if (mp.count(a[i]) != 0)
        {
            nums.push_back(mp[a[i]]);
        }
    }
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = lower_bound(res.begin(), res.end(), nums[i]);
        if (it == res.end())
            res.push_back(nums[i]);
        else
            *it = nums[i];
    }
    cout << m - res.size();

    return 0;
}