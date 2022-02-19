class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
      int n=nums.size();  
      int res=INT_MAX, mini=INT_MAX;
      for(int i=0;i<n;i++){
        nums[i]= nums[i]%2 ? nums[i]*2 : nums[i];
        mini=min(nums[i], mini);
      }
      make_heap(nums.begin(), nums.end());
      while(nums[0]%2==0){
        res=min(res, nums[0] - mini);
        mini= min(mini, nums[0]/2);
        nums.push_back(nums[0]/2);
        push_heap(nums.begin(), nums.end());
        pop_heap(nums.begin(), nums.end());
        nums.pop_back();
        
      }
      
      return min(res, nums[0]-mini);
      
      
    }
};