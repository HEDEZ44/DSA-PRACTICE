class Solution {
public:
  
  bool canpermute(int idx, int i, vector<int>& nums){
    for(int j=idx;j<i;j++){
      if(nums[j]==nums[i])
        return false;
      
    }
    return true;
  }
  
  void permute(vector<int>& nums, vector<vector<int>>& ans, int idx){
    if(idx==nums.size()){
      ans.push_back(nums);
      return;
    }
    
    for(int i=idx;i<nums.size();i++){
      if(i!=idx and !canpermute(idx,i,nums)) continue;
      swap(nums[i], nums[idx]);
      permute(nums, ans, idx+1);
      swap(nums[i], nums[idx]);
      
    }
    
    
  }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<vector<int>> ans;
      sort(nums.begin(), nums.end());
      permute(nums,ans,0);
      return ans;
        
    }
};



//DIFFERENT APPROACH "nums" PASSING BY VALUE

class Solution {
public:
  
  void permute(vector<int> nums, vector<vector<int>>& ans, int idx){
    if(idx==nums.size()){
      ans.push_back(nums);
      return;
    }
    
    for(int i=idx;i<nums.size();i++){
      if(i!=idx and nums[idx]==nums[i]) continue;
      swap(nums[i], nums[idx]);
      permute(nums, ans, idx+1);
      
      
    }
    
    
  }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<vector<int>> ans;
      sort(nums.begin(), nums.end());
      permute(nums,ans,0);
      return ans;
        
    }
};
