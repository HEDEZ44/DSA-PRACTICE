class Solution {
public:
  
  
  void solve(string s, vector<string>& ans, unordered_map<string, bool>& mp, int removals){
    if(mp[s])
      return;
    mp[s]=true;
    
    if(removals==0){
      if(find_removals(s)==0){
        ans.push_back(s);
      }
      return;
    }
    for(int i=0;i<s.length();i++){
      string left=s.substr(0,i);
      string right=s.substr(i+1);
      string join=left+right;
      solve(join,ans,mp,removals-1);
    }
    
    
  }
  
  int find_removals(string S){
    stack<char> st;
    for(int i=0;i<S.length();i++){
      if(S[i]=='('){
        st.push('(');
      }
      else if(S[i]==')'){
        if(!st.empty() && st.top()=='(')
          st.pop();
        else
          st.push(')');
      }
    }
    return st.size();
  }
  
    vector<string> removeInvalidParentheses(string s) {
      
      unordered_map<string, bool> mp;
      vector<string> ans;
      int removals=find_removals(s);
      solve(s,ans,mp,removals);
      return ans;
      
    }
};

//didn't use backtracking


