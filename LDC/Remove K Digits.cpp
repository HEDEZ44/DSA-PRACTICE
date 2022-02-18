class Solution {
public:
    string removeKdigits(string num, int k) {
      string ans="";
      for(char c:num){
        while(ans.length() && c<ans.back() && k){
          ans.pop_back();
          k--;
        }
        
        if(ans.length() || c!='0') ans.push_back(c);
      }
      while(ans.length() && k--) ans.pop_back();
      
      return ans.length()==0?"0": ans;
        
    }
};