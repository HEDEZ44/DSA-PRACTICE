class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
      long long ans=0;
      int n=nums.size();
      int prev=nums[n-1];
      for(int i=n-2;i>=0;i--){
        int noOfTimes=nums[i]/prev;
        if(nums[i]%prev){
          noOfTimes++;
          prev=nums[i]/noOfTimes;
        }
        ans+=noOfTimes-1;
      }
      return ans;
    }
};