#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool is_valid(ll add, ll sub, ll mul, ll div)
{
    ll a = (add + sub) / 2;
    ll b = (add - sub) / 2;

    if (a < 1 || a > 10000)
        return false;
    if (b < 1 || b > 10000)
        return false;

    ll flag = 0;
    if (a + b == add)
        flag++;
    if (a - b == sub)
        flag++;
    if (a * b == mul)
        flag++;
    if (b != 0 && a / b == div)
        flag++;

    if (flag == 4)
    {
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        ll val[4];
        for (int i = 0; i < 4; i++)
            cin >> val[i];

        ll arr[4] = {0, 1, 2, 3};

        pair<ll, ll> ans = {-1, -1};
        do
        {

            if (is_valid(val[arr[0]], val[arr[1]], val[arr[2]], val[arr[3]]))
            {
                ans.first = (val[arr[0]] + val[arr[1]]) / 2;
                ans.second = (val[arr[0]] - val[arr[1]]) / 2;
                break;
            }
        } while (next_permutation(arr, arr + 4));

        cout << ans.first << ' ' << ans.second << endl;
    }

    return 0;
}
