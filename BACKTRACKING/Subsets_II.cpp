class Solution {
public:
      void solve(vector<vector<int>>& ans, vector<int>& v, vector<int>& nums, int idx ){
      
      ans.push_back(v);
      
      for(int i=idx;i<nums.size();i++){
        if(i!=idx && nums[i]==nums[i-1]) continue;
        v.push_back(nums[i]);
        solve(ans,v,nums,i+1);
        v.pop_back();
      }
    }
  
  
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      vector<vector<int>> ans;
      vector<int> v;
      solve(ans,v,nums,0);
      return ans;
        
    }
};