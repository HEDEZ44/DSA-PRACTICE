#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int n = str.length();
    int m;
    cin >> m;
    vector<int> nums(m);
    for (int i = 0; i < m; i++)
    {
        cin >> nums[i];
        }

    for (auto it : nums)
    {
        int idx = n - it;
        reverse(str.begin() + it, str.begin() + idx);
    }
    cout << str;
    return 0;
}