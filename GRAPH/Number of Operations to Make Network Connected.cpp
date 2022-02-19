class Solution {
public:
  void dfs(vector<vector<int>>& adj, vector<bool>& vis, int i){
    vis[i]= true;
    for(auto c:adj[i]){
      if(!vis[c]) dfs(adj, vis, c);
    }
  }
    int makeConnected(int n, vector<vector<int>>& connections) {
      int m=connections.size();
      if((n - m)>1) return -1;
      vector<bool> vis(n, false);
      vector<vector<int>> adj(n);
      for(int i=0;i<m;i++){
        adj[connections[i][0]].push_back(connections[i][1]);
        adj[connections[i][1]].push_back(connections[i][0]);
      }
      int components=0;
      for(int i=0;i<n;i++){
        if(!vis[i]){
          dfs(adj, vis, i);
          components++;
        }
      }
      return components-1;
      
        
    }
};