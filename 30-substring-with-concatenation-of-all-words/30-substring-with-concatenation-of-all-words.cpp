class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
      
      unordered_map<string, int> mp;
        
        for(auto i: words){
            mp[i]++;
        }
      
      
      vector<int> ans;
      int k=words[0].length();
      int len=k*words.size();
      int n=s.length();
      
      for(int i=0;i<n-len+1;i++){
        unordered_map<string, int> map;
        
        for(int l=0;l<words.size();l++){
          string temp=s.substr(i+k*l, k);
          if(mp.count(temp)==0) break;
          else map[temp]++;
        }
        if(mp==map) ans.push_back(i);
      }
      return ans;
    }
};