
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	bool isPossible(int N, vector<pair<int, int>> &pre)
	{

		vector<int> adj[N];
		for (auto it : pre)
		{
			adj[it.first].push_back(it.second);
		}

		queue<int> q;
		vector<int> indegree(N, 0);
		for (int i = 0; i < N; i++)
		{
			for (auto it : adj[i])
				indegree[it]++;
		}
		for (int i = 0; i < N; i++)
		{
			if (indegree[i] == 0)
				q.push(i);
		}

		int count = 0;
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			count++;
			for (auto it : adj[node])
			{
				indegree[it]--;
				if (indegree[it] == 0)
				{
					q.push(it);
				}
			}
		}
		if (count == N)
			return true;
		return false;
	}
};

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int N, P;
		vector<pair<int, int>> prerequisites;
		cin >> N;
		cin >> P;
		for (int i = 0; i < P; ++i)
		{
			int x, y;
			cin >> x >> y;
			prerequisites.push_back(make_pair(x, y));
		}

		Solution ob;
		if (ob.isPossible(N, prerequisites))
			cout << "Yes";
		else
			cout << "No";
		cout << endl;
	}
	return 0;
}

// make graph then apply topo sort

/// second Method

/*
	Time Complexity : O(Q * log(N * M))
	Space Complexity : O(N * M)

	Where 'Q' is the number of queries.
	Where 'N' is the number of rows and 'M' is the number of columns.
*/

// Function for finding parent of a node using path compression.
int getParent(int i, vector<int> &parent)
{
	if (i == parent[i])
	{
		return i;
	}

	return parent[i] = getParent(parent[i], parent);
}

// Function for performing union of two components using union by rank.
void Union(int u, int v, vector<int> &parent, vector<int> &rank)
{
	int a = getParent(u, parent);
	int b = getParent(v, parent);
	if (a == b)
	{
		return;
	}

	if (rank[a] == rank[b])
	{
		rank[a]++;
	}

	if (rank[a] > rank[b])
	{
		parent[b] = a;
	}
	else
	{
		parent[a] = b;
	}
}

// Funtion to check whether 'X', 'Y' is valid or not.
bool valid(int x, int y, int n, int m, vector<vector<int>> &grid)
{
	if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0)
	{
		return 0;
	}
	return 1;
}

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q)
{
	// For storing the parent nodes.
	vector<int> parent(n * m);

	// For storing the rank of the nodes.
	vector<int> rank(n * m);

	for (int i = 0; i < n * m; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}

	vector<int> ans;

	// 'GRID[i][j]' = 0 or 1, 0 representing water and 1 representing land.
	vector<vector<int>> grid(n, vector<int>(m));

	vector<int> dx = {1, 0, -1, 0};
	vector<int> dy = {0, 1, 0, -1};

	int numberOfIslands = 0;

	for (int i = 0; i < (int)q.size(); i++)
	{
		int x = q[i][0], y = q[i][1];

		// This cell is already a land.
		if (grid[x][y] == 1)
		{
			ans.push_back(numberOfIslands);
			continue;
		}

		numberOfIslands++;

		// Getting the number of Islands after union with neighboours.
		for (int dir = 0; dir < 4; dir++)
		{
			int dxx = x + dx[dir];
			int dyy = y + dy[dir];

			if (!valid(dxx, dyy, n, m, grid))
			{
				continue;
			}

			if (getParent(dxx * m + dyy, parent) != getParent(x * m + y, parent))
			{
				numberOfIslands--;
			}

			Union(dxx * m + dyy, x * m + y, parent, rank);
		}

		// Converting the water body to a land.
		grid[x][y] = 1;
		ans.push_back(numberOfIslands);
	}
	// Return the answer.
	return ans;
}