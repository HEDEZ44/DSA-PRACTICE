class Solution {
public:

  int maxgold(vector<vector<int>>& grid, int i, int j, int m, int n){
    if(i<0 || i>=m || j<0 || j>=n || grid[i][j]<=0) return 0;
    grid[i][j]= -grid[i][j];
    int left = maxgold(grid, i, j-1, m, n);
    int right = maxgold(grid, i, j+1, m, n);
    int up = maxgold(grid, i-1, j, m, n);
    int down = maxgold(grid, i+1, j, m, n);
    grid[i][j]= -grid[i][j];
    int gold = max({up,down,left,right}) + grid[i][j];
    return gold;
    
  }
  
  
    int getMaximumGold(vector<vector<int>>& grid) {
      
      int m=grid.size();
      int n=grid[0].size();
      
      int maxg=0;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(grid[i][j]>0){
            int gold=maxgold(grid, i, j, m, n);
            maxg= max(maxg,gold);
          }
        }
      }
      return maxg;
        
    }
};