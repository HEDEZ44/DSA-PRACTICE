


#include <bits/stdc++.h>
using namespace std;


 


class Solution{
    public:
    bool isSafe(int newi, int newj, vector<vector<int>>& vis, vector<vector<int>>& m, int n){
        if(newi<0 || newi>=n || newj<0 || newj>=n || vis[newi][newj]==1 || m[newi][newj]==0) return false;
        else return true;
    }
    void solve(vector<vector<int>> &m, vector<vector<int>> &vis, int n, vector<string >& ans, int i, int j, string sub){
        if(i==n-1 && j==n-1){
            ans.push_back(sub);
            return;
        } 
        
        vis[i][j]=1;
        
        int newi= i+1;
        int newj=j;
        if(isSafe(newi, newj, vis, m, n)){
            sub.push_back('D');
            solve(m,vis,n,ans,newi,newj,sub);
            sub.pop_back();
        }
        
        
        newi= i-1;
        newj=j;
        if(isSafe(newi, newj, vis, m, n)){
            sub.push_back('U');
            solve(m,vis,n,ans,newi,newj,sub);
            sub.pop_back();
        }
        
        
        newi= i;
        newj=j-1;
        if(isSafe(newi, newj, vis, m, n)){
            sub.push_back('L');
            solve(m,vis,n,ans,newi,newj,sub);
            sub.pop_back();
        }
        
        
        
        newi= i;
        newj=j+1;
        if(isSafe(newi, newj, vis, m, n)){
            sub.push_back('R');
            solve(m,vis,n,ans,newi,newj,sub);
            sub.pop_back();
        }
        vis[i][j]=0;
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string> ans;
        if(m[0][0]==0) return ans;
        vector<int> v(n, 0);
        vector<vector<int>> vis(n, v);
        solve(m, vis, n, ans, 0, 0, "");
        return ans;
        
    }
};

    




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
}  