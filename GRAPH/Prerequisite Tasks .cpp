
#include<bits/stdc++.h>
using namespace std;

 
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    
	    vector<int> adj[N];
	    for(auto it:pre){
	       adj[it.first].push_back(it.second);
	    }
	    
	    queue<int> q;
	    vector<int> indegree(N, 0);
	    for(int i=0;i<N;i++){
	        for(auto it: adj[i]) indegree[it]++;
	    }
	    for(int i=0;i<N;i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    
	    int count=0;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        count++;
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0){
	                q.push(it);
	            }
	        }
	    }
	    if(count==N) return true;
	    return false;
	    
	}
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
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


//make graph then apply topo sort