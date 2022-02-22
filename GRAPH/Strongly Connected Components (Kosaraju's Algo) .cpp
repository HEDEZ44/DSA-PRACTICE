
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void revDfs(int node, vector<int> &vis, vector<int> transpose[])
    {
        vis[node] = 1;
        for (auto it : transpose[node])
        {
            if (!vis[it])
                revDfs(it, vis, transpose);
        }
    }
    void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, st, vis, adj);
            }
        }
        st.push(node);
    }
    int kosaraju(int n, vector<int> adj[])
    {

        stack<int> st;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, st, vis, adj);
            }
        }

        vector<int> transpose[n];
        for (int i = 0; i < n; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                transpose[it].push_back(i);
            }
        }
        int count = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!vis[node])
            {
                revDfs(node, vis, transpose);
                count++;
            }
        }
        return count;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}
