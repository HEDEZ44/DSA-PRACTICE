class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      int ans=0;
      unordered_map<int, int> mp;
      int sum=0;
      mp.insert({0,-1});
      for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
          sum+=-1;
        }
        else if(nums[i]==1){
          sum+=1;
        }
        if(mp.find(sum) != mp.end()){
          int idx=mp[sum];
          int len= i-idx;
          if(len>ans){
            ans=len;
          }
        }
        else{
          mp[sum]=i;
        }
      }
      return ans;
        
    }
};