class Solution {
public:
  
  void generate(int open, int close, string str, vector<string>& v){
    if(open==0 && close==0){
      v.push_back(str);
      return;
    }
    if(open!=0){
      str.push_back('(');
      generate(open-1,close,str,v);
      str.pop_back();
    }
    if(close>0 && open<close){
      str.push_back(')');
      generate(open,close-1,str,v);
      str.pop_back();
    }
  }
  
  
  
    vector<string> generateParenthesis(int n) {
        
      int close=n;
      int open=n;
      string str="";
      vector<string> v;
      generate(open,close,str,v);
      return v;
    }
};