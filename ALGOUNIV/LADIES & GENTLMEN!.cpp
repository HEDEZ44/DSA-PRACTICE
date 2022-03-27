#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    if (n == 1)
        cout << 1;
    else if (n == 2)
        cout << 3;
    else
    {
        long long ans = 3;
        long long a = 1, b = 2;
        for (int i = 3; i <= n; i++)
        {
            long long temp = b;
            b = (a + b) % 1000000007;
            a = temp;
            ans = (ans + b) % 1000000007;
        }
        cout << ans;
    }
    return 0;
}