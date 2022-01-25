// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++
#define MAX 5

class Solution{
    
    private:
    
    
        bool isSafe(int x, int y, int n, vector<vector<int>>& m, int v[][MAX] ){
        if(x==-1 || x==n || y==-1 || y==n || v[x][y]==1 || m[x][y]==0){
            return  false;
        }
        return true;
    }
    
    
    void solve(vector<vector<int>>& m, int v[][MAX], int n, int x, int y, vector<string>& ans, string path){
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        
        v[x][y]=1;
        
        //down
        int newx=x+1;
        int newy=y;
        
        if(isSafe(newx, newy, n, m, v)){
            path.push_back('D');
            solve(m,v,n,newx,newy,ans,path);
            path.pop_back();
        }
        
        //right
        newx=x;
        newy=y+1;
        if(isSafe(newx, newy, n, m, v)){
            path.push_back('R');
            solve(m,v,n,newx,newy,ans,path);
            path.pop_back();
        }
        
        //up
        newx=x-1;
        newy=y;
        if(isSafe(newx, newy, n, m, v)){
            path.push_back('U');
            solve(m,v,n,newx,newy,ans,path);
            path.pop_back();
        }
        
        //left
        newx=x;
        newy=y-1;
        if(isSafe(newx, newy, n, m, v)){
            path.push_back('L');
            solve(m,v,n,newx,newy,ans,path);
            path.pop_back();
        }
        
        v[x][y]=0;
        
    }
    
    
    public:
    

    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0]==0){
            return ans;
        }
        int v[n][MAX];
        memset(v, 0, sizeof(v));
        
        string path="";
        solve(m, v, n, 0, 0, ans, path);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends