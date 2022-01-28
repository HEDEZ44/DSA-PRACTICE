class CombinationIterator {
  string st;
  int len;
  int i;
  vector<string> v;
public:
  void combi(string c, vector<string>& v, string &str, int idx, int len){
    if(str.length()==len){
      v.push_back(str);
      return;
    }
    for(int i=idx;i<c.length();i++){
      str.push_back(c[i]);
      combi(c,v,str,i+1,len);
      str.pop_back();
      
    }
  }
  
    CombinationIterator(string c, int len) {
      string ch="";
      combi(c,v,ch,0,len);
      i=0;
        
    }
    
    string next() {
      return v[i++];   
    }
    
    bool hasNext() {
        if(i<v.size())
          return true;
      return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */