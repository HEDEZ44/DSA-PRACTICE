class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
      vector<int> prev={1,2,3,4,5,6,7,8,9};
      for(int l=2;l<=n;l++){
        vector<int> curr;
        for(auto it:prev){
          int y=it%10;
          if(y+k<10) curr.push_back(it*10+y+k);
          if(k>0 && y-k>=0) curr.push_back(it*10+y-k);
        }
        prev=curr;
      }
      return prev;
    }
};