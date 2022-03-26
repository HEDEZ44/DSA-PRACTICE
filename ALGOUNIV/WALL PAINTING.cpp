#include <bits/stdc++.h>
using namespace std;

int mat[1005][1005] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    while (n--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i < x2; i++)
            mat[i][y1]++, mat[i][y2]--;
    }

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 1; j < 1000; j++)
            mat[i][j] += mat[i][j - 1];
    }

    int ans = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 1; j < 1000; j++)
            ans += (mat[i][j] == k);
    }
    cout << ans;
    return 0;
}