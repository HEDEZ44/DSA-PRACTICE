class Solution {
public:

  
void combisum(vector<vector<int>>& ans, vector<int>& c, int t, vector<int>& v, int idx){
    if(!t){
      ans.push_back(v);
      return;
    }
 
  for(int i=idx;i<c.size() && t>=c[i];i++){
    
     
      v.push_back(c[i]);
      combisum(ans,c,t-c[i],v,i);
      v.pop_back();
     
    
  }
  }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
      sort(c.begin(),c.end());
      vector<vector<int>> ans;
      vector<int> v;
      combisum(ans,c,t,v,0);
      return ans;
      
        
    }
};