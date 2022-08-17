class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> codes{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
      unordered_map<string, int> map;
      for(auto it:words){
        string code="";
        for(char c:it){
          code+=codes[c-'a'];
        }
        map[code]++;
      }
      return map.size();
    }
};