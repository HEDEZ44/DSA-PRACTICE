#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<int> indeg(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        indeg[a]++;
        indeg[b]++;
    }
    int count = 0;

    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (auto it : adj[node])
                {
                    q.push(it);
                    vis[it] = true;
                }
            }
            count++;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] > 1 || indeg[i] == 0)
            cnt++;
    }
    if (cnt == count)
        cout << count;

    return 0;
}