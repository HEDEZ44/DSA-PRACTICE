class Solution {
public:
    int firstUniqChar(string s) {
      unordered_map<char, int> map;
      for(auto it:s) map[it]++;
      int i;
      for(i=0;i<s.length();i++) if(map[s[i]]==1) break;
      return i==s.length()?-1:i;
    }
};