

class Solution
{
	
	vector<int> row = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> col = {1, 2, 2, 1, -1, -2, -2, -1};
public:
bool isvalid(int newx, int newy, int n){
	if(newx>=n || newx<0 || newy>=n || newy<0){
		return false;
	}
	return true;
}

void solve(set<vector<vector<int>>>& result, vector<vector<int>>& visited, int n, int x, int y, int pos){
	
	
	if(pos==n*n){
		visited[x][y]=n*n;
		result.insert(visited);
		return;
	}
	
	visited[x][y]=pos;

	for(int i=0;i<8;i++){
		int newx=x+row[i];
		int newy=y+col[i];
		
		if(isvalid(newx,newy,n) && (visited[newx][newy]==0 || visited[newx][newy]==n*n)){
			solve(result,visited,n,newx,newy,pos+1);
		}
		
	}
	visited[x][y]=0;
	
	
}






	set<vector<vector<int>>> _knightTour(int n)
	{
		
		set<vector<vector<int>>> result;
		if(n==1){
			return {{{1}}};
		}
		if(n==2 || n==3 || n==4){
			return {};
		}
		
		vector<vector<int>> visited;
		vector<int> v;
		for(int i=0;i<n;i++){
			v.push_back(0);
		}
		for(int i=0;i<n;i++){
			visited.push_back(v);
		}
		

		solve(result,visited, n, 0, 0, 1);
		

		return result;
	}
};
