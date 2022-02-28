bool valid(int x, int y, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis)
{
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0 || vis[x][y] == 1)
    {
        return 0;
    }

    return 1;
}

// Funtion to mark all the reachable vertex from 'X', 'Y' as visited.
void dfs(int x, int y, vector<int> &dx, vector<int> &dy, vector<vector<int>> &grid, vector<vector<int>> &visited)
{
    visited[x][y] = 1;

    for (int dir = 0; dir < 4; dir++)
    {
        int X = x + dx[dir], Y = y + dy[dir];

        if (!valid(X, Y, grid.size(), grid[0].size(), grid, visited))
        {
            continue;
        }
        dfs(X, Y, dx, dy, grid, visited);
    }
}

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q)
{
    // To store the number of islands after each query.
    vector<int> ans;

    vector<vector<int>> grid(n, vector<int>(m));

    // Directions to the neighbouring cells of 'X', 'Y'.
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    for (int i = 0; i < (int)q.size(); i++)
    {
        int x = q[i][0], y = q[i][1];

        grid[x][y] = 1;

        int noOfIslands = 0;

        vector<vector<int>> visited(n, vector<int>(m));

        // Computing the number of connected components int the grid.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    dfs(i, j, dx, dy, grid, visited);
                    noOfIslands++;
                }
            }
        }
        ans.push_back(noOfIslands);
    }
    // Return the answer.
    return ans;
}