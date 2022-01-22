class Solution {
public:
  
  
  
    vector<int> topKFrequent(vector<int>& nums, int k) {
      if(nums.size()==1 || nums.size()==0)
        return nums;
        unordered_map<int,int> mp;
      for(int i=0;i<nums.size();i++){
        if(mp.find(nums[i])==mp.end()){
          mp[nums[i]]=1;
        }
        else
          mp[nums[i]]++;
      }
      
      vector<pair<int,int>> v;
      for(auto it:mp){
        v.push_back(it);
        
      }
      sort(v.begin(),v.end(),[&](pair<int,int>& a,pair<int,int>& b){
        return a.second>b.second;
      });
      vector<int> l;
      int i=0;
      for(auto it:v){
        
        if(i==k)
          break;
        l.push_back(it.first);
        i++;
          
        
      }
      return l;
      
      
    }
};