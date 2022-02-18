
#include<bits/stdc++.h>
using namespace std;

 

class Solution 
{
    public:
    
    bool isSafe(int x, int y, int N){
        if(x<0 || x>=N || y<0 || y>=N) return false;
        return true;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&Targetpos,int N)
	{
	    int tx=Targetpos[0]-1;
	    int ty=Targetpos[1]-1;
	    vector<int> v(N, 0);
	    vector<vector<int>> ans(N, v);
	    int dx[]={-2, -1, 1, 2, -2, -1, 1, 2};
	    int dy[]={-1, -2, -2, -1, 1, 2, 2, 1};
	    queue<pair<int, int>> q;
	    q.push({KnightPos[0]-1, KnightPos[1]-1});
	    while(!q.empty()){
	        int x=q.front().first;
	        int y=q.front().second;
	        q.pop();
	        for(int i=0;i<8;i++){
	            int newx=x+dx[i];
	            int newy=y+dy[i];
	            if(isSafe(newx, newy, N) && ans[newx][newy]==0){
	                ans[newx][newy]=ans[x][y]+1;
	                q.push({newx, newy});
	            }
	            
	        }
	    }
	    return ans[tx][ty];
	}
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  