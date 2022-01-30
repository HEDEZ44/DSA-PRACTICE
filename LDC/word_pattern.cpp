class Solution {
public:
    bool wordPattern(string pattern, string s) {
      
      int n= pattern.length();
      stringstream str(s);
      unordered_map<string, int> m1;
      unordered_map<char, int> m2;
      int i=0;
      string word;
      
      while( str >> word){
        if(i==n || m1[word] != m2[pattern[i]]) return false;
        
        m1[word]=m2[pattern[i]] = i+1;
        i++;
      }
      return i==n;
        
    }
};