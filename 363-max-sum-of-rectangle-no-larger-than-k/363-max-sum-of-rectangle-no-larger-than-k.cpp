class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
      int rows=matrix.size(), cols=matrix[0].size(), res=INT_MIN;
      for(int l=0;l<cols;l++){
        vector<int> nums(rows);
        for(int j=l;j<cols;j++){
          for(int i=0;i<rows;i++)
            nums[i]+=matrix[i][j];
          set<int> s={0};
          int sum=0;
          for(auto it:nums){
            sum+=it;
            auto K=s.lower_bound(sum-k);
            if(K!=s.end()){
              res=max(res, sum-*K);
            }
            s.insert(sum);
          }
        }
      }
      return res;
    }
};