
#include<bits/stdc++.h>
using namespace std;

 
class Solution
{
	public:
	
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distTo(V, INT_MAX);
        pq.push(make_pair(0,S));
        distTo[S]=0;
        
        while(!pq.empty()){
            int dist=pq.top().first;
            int prev=pq.top().second;
            pq.pop();
            
            vector<vector<int>> it= adj[prev];
            for(int i=0;i<it.size();i++){
                int next=it[i][0];
                int nextDist=it[i][1];
                if(distTo[next]>dist+nextDist){
                    distTo[next]=dist+nextDist;
                    pq.push(make_pair(distTo[next], next));
                }
            }
        }
        return distTo;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  