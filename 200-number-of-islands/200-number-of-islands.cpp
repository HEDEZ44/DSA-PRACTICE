class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
      vector<int> offsets={0, 1, 0, -1, 0};
      int islands=0, n=grid.size(), m=grid[0].size();
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(grid[i][j]=='1'){
            islands++;
            grid[i][j]=0;
            queue<pair<int, int>> q;
            q.push({i, j});
            while(!q.empty()){
              auto k=q.front();
              q.pop();
              for(int i=0;i<4;i++){
                int x=k.first+offsets[i], y=k.second+offsets[i+1];
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y]=='1'){
                  grid[x][y]=0;
                  q.push({x, y});
                }
              }
            }
          }
        }
      }
      return islands;
    }
};