class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
      long long res=0;
      unordered_map<int, int> mp;
      for(int i:nums){
        long long gcd1= gcd(i, k);
        for(auto it:mp){
          res+= gcd1*it.first % k ? 0 : it.second;
        }
        mp[gcd1]++;
      }
      return res;
      
    }
};