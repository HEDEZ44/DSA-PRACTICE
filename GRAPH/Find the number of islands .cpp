
#include <bits/stdc++.h>
using namespace std;

 
class Solution {
  public:
    
    void visit(vector<vector<char>>& grid, vector<vector<int>>& visited, int x, int y, int m, int n){
        if(x<0 || x>=m || y<0 || y>=n || visited[x][y]==1 || grid[x][y]=='0') return;
        
        visited[x][y]=1;
        
        int newx=x-1;
        int newy=y;
        visit(grid, visited, newx, newy, m, n);
        
        
        
        newx=x+1;
        newy=y;
        visit(grid, visited, newx, newy, m, n);
        
        
        newx=x;
        newy=y-1;
        visit(grid, visited, newx, newy, m, n);
        
        
        newx=x;
        newy=y+1;
        visit(grid, visited, newx, newy, m, n);
        
        
        
        newx=x-1;
        newy=y+1;
        visit(grid, visited, newx, newy, m, n);
        
        
        
        newx=x+1;
        newy=y+1;
        visit(grid, visited, newx, newy, m, n);
        
        
        newx=x-1;
        newy=y-1;
        visit(grid, visited, newx, newy, m, n);
        
        
        newx=x+1;
        newy=y-1;
        visit(grid, visited, newx, newy, m, n);
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<int> v(grid[0].size(), 0);
        vector<vector<int>> visited(grid.size(), v);
        int count=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                   count++;
                   visit(grid, visited, i, j, m, n);
                }
            }
        }
        return count;
    }
};


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  