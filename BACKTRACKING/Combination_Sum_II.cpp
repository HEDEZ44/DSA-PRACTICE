class Solution {
public:
  void combisum(vector<int>& c, int t, vector<int>& v, vector<vector<int>>& ans, int idx ){
    if(!t){
      ans.push_back(v);
      return;
    }
  
  
  for(int i=idx; i<c.size() && t>=c[i]; i++){
    if(i!=idx && c[i]==c[i-1]) continue;
    v.push_back(c[i]);
    combisum(c,t-c[i],v,ans,i+1);
    v.pop_back();
  }
  
  } 
  
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
      sort(c.begin(),c.end());
      vector<vector<int>> ans;
      int idx=0;
      vector<int> v;
      combisum(c,t,v,ans,idx);
      return ans;
        
    }
};