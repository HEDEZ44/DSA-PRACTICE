class Solution {
public:
  
  bool ispalindrome(int start, int end, string s){
    while(start<=end){
      if(s[start++] != s[end--]){
        return false;
      }
    }
    return true;
  }
  
  
    void solve(vector<vector<string>>& ans, vector<string>& v, int idx, string s){
      
      if(idx==s.length()){
        ans.push_back(v);
        return;
      }
      for(int i=idx;i<s.length();i++){
        if(ispalindrome(idx,i,s)){
          v.push_back(s.substr(idx,i-idx+1));
          solve(ans,v,i+1,s);
          v.pop_back();
        }
        
      }
      
    }
    vector<vector<string>> partition(string s) {
      
      vector<vector<string>> ans;
      vector<string> v;
      
      
      solve(ans,v,0,s);
      cout<<s.substr(0,2);
      return ans;
      
        
    }
};


