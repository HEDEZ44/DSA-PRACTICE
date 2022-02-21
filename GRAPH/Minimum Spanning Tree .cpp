
#include<bits/stdc++.h>
using namespace std;

 


class Solution
{
	public:
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        int dis=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int> vis(V, 0);
        q.push({0, 0});
        while(!q.empty()){
            auto n=q.top();
            q.pop();
            int node= n.second;
            int d=n.first;
            if(!vis[node]){
                vis[node]=1;
                dis+=d;
                for(auto it:adj[node]){
                    if(!vis[it[0]]) q.push({it[1], it[0]});
                }
            }
        }
        return dis;
    }
};




int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  