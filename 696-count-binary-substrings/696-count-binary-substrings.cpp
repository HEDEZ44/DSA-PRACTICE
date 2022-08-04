class Solution {
public:
    int countBinarySubstrings(string s) {
        int curr=1, pre=0, res=0;
        for(int i=1;i<s.length();i++){
          if(s[i]==s[i-1]) curr++;
          else{
            res+=min(curr, pre);
            pre=curr;
            curr=1;
          }
        }
      res+=min(curr, pre);
      return res;
    }
};