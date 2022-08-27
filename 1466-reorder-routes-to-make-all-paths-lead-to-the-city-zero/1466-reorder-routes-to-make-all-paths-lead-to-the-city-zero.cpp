class Solution {
public:
  int solve(vector<int> adj[], vector<bool>& vis, int from){
    vis[from]=true;
    int change=0;
    for(auto to:adj[from]){
      if(!vis[abs(to)]){
        change+= solve(adj, vis, abs(to)) + (to>0);
      }
    }
    return change;
  }
    int minReorder(int n, vector<vector<int>>& connections) {
      vector<int> adj[n];
      for(auto it:connections){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(-it[0]);
      }
      vector<bool> vis(n);
      return solve(adj, vis, 0);
    }
};