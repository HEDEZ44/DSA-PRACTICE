#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    int dist = abs(x - y);
    int ans;
    if (abs(x - a) < abs(x - b) && abs(x - a) + abs(y - b) < dist)
    {
        ans = abs(x - a) + abs(y - b);
    }
    else if (abs(x - a) > abs(x - b) && abs(x - b) + abs(y - a) < dist)
    {
        ans = abs(x - b) + abs(y - a);
    }
    else
        ans = dist;

    cout << ans << endl;
}