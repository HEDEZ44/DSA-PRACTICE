class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int n=nums.size(), k, i;
      for(k=n-2;k>=0;k--){
        if(nums[k+1]>nums[k]) break;
      }
      sort(nums.begin()+k+1, nums.end());
      if(k==-1) return;
      for(i=k+1; i<n;i++){
        if(nums[i]>nums[k]) break;
      }
      swap(nums[i], nums[k]);
    }
};