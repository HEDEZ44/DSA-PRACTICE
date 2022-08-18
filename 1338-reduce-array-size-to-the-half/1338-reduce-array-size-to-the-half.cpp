class Solution {
public:
    int minSetSize(vector<int>& arr) {
      unordered_map<int, int> map;
      for(auto it:arr){
        map[it]++;
      }
      vector<pair<int, int>> nums;
      for(auto it:map){
        nums.push_back({it.second, it.first});
      }
      sort(nums.begin(), nums.end(), [](auto& a, auto& b){
        return a.first>b.first;
      });
      int ans=0, cnt=0;
      int n=arr.size();
      for(auto it:nums){
        if(ans<n/2){
          ans+=it.first;
          cnt++;
        }
        else break;
      }
      return cnt;
    }
};