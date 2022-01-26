class Solution {
public:
  
  
    void combination(vector<vector<int>>& ans, vector<int> v, int n, int k, int idx ){
      if(v.size()==k){
        ans.push_back(v);
        return;
      }
      
      for(int i=idx;i<=n;i++){
        v.push_back(i);
        combination(ans,v,n,k,i+1);
        v.pop_back();
      }
    }
    
    vector<vector<int>> combine(int n, int k) {
      
      vector<vector<int>> ans;
      vector<int> v;
      int start=1;
      combination(ans,v,n,k,start);
      return ans;
        
        
    }
};