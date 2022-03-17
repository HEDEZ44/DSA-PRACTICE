#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> dist(n + 1, 0);
    for (long long i = 1; i <= n; i++)
    {
        long long a;
        cin >> a;
        dist[i] = dist[i - 1] + a;
    }
    long long k;
    cin >> k;
    long long i = 1;
    while (k--)
    {
        int t;
        long long d;
        cin >> t >> d;
        d = d % n;
        if (t == 1)
        {
            long long j = (i + d) % n;
            if (j == 0)
                j = n;
            if (i == j)
                cout << 0 << endl;
            else if (j > i)
            {
                long long dist1 = dist[j] - dist[i];
                long long dist2 = dist[n] + dist[i] - dist[j];
                cout << min(dist1, dist2) << endl;
            }
            else
            {
                long long dist1 = dist[n] + dist[j] - dist[i];
                long long dist2 = dist[i] - dist[j];
                cout << min(dist1, dist2) << endl;
            }
            i = j;
        }
        else if (t == -1)
        {
            long long j;
            if (i > d)
                j = i - d;
            else if (i == d)
                j = n;
            else if (i < d)
            {
                j = n - (d - i);
            }
            if (i == j)
                cout << 0 << endl;
            else if (j > i)
            {
                long long dist1 = dist[j] - dist[i];
                long long dist2 = dist[n] + dist[i] - dist[j];
                cout << min(dist1, dist2) << endl;
            }
            else
            {
                long long dist1 = dist[n] + dist[j] - dist[i];
                long long dist2 = dist[i] - dist[j];
                cout << min(dist1, dist2) << endl;
            }
            i = j;
        }
    }
    return 0;
}