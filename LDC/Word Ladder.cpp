class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      
      if(wordList.size()==0 || find(wordList.begin(), wordList.end(), endWord)==wordList.end())
          return 0;
      
      unordered_set<string> list(wordList.begin(), wordList.end());
      queue<string> q;
      q.push(beginWord);
      int ladder=1;
      while(!q.empty()){
        int n=q.size();
        for(int k=0;k<n;k++){
        string word=q.front();
        q.pop();
        if(word==endWord)
          return ladder;
        list.erase(word);
        for(int i=0;i<word.length();i++){
          char c=word[i];
          for(int j=0;j<26;j++){
            word[i]='a'+j;
            if(list.find(word)!=list.end()){
              q.push(word);
              
            }
          }
          word[i] = c;
        }
        }
        ladder++;
        
      }
      return 0;
      
      
      
    }
};