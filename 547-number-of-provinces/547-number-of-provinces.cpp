class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
      int n=isConnected.size();
      vector<int> adj[n+1];
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(i!=j && isConnected[i][j]==1){
            adj[i+1].push_back(j+1);
            adj[j+1].push_back(i+1);
          }
        }
      }
      vector<int> vis(n+1, 0);
      int cnt=0;
      queue<int> q;
      for(int i=1;i<=n;i++){
        if(vis[i]==0){
          vis[i]=1;
          q.push(i);
          cnt++;
          while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
              if(vis[it]==0){
                vis[it]=1;
                q.push(it);
              }
            }
          }
        }
      }
      return cnt;
    }
};