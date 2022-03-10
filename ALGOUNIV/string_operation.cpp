#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int m;
    cin >> m;
    int n = str.length();
    vector<int> nums(n / 2);
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        nums[a - 1]++;
    }
    int car = 0;
    for (int i = 0; i < n / 2; i++)
    {
        car += nums[i];
        if (car & 1)
        {
            swap(str[i], str[n - i - 1]);
        }
    }
    cout << str;

    return 0;
}