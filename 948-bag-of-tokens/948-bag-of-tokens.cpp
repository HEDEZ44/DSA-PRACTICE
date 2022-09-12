class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
      int score=0;
      int maxi=0;
      int i=0, j=tokens.size()-1;
      sort(tokens.begin(), tokens.end());
      while(i<=j){
        if(power>=tokens[i]){
          power-=tokens[i];
          i++;
          score++;
          maxi=max(maxi, score);
        }
        else if(power<tokens[i] && score>0){
          power+=tokens[j];
          j--;
          score--;
          maxi=max(maxi, score);
        }
        else{
          break;
        }
      }
      return maxi;
    }
};