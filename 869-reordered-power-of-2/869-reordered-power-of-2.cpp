class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string num=sorted(n);
        for(int i=0;i<32;i++){
          if(sorted(1<<i)==num) return true;
        }
      return false;
    }
  string sorted(int n){
    string res=to_string(n);
    sort(res.begin(), res.end());
    return res;
  }
};