class Solution {
public:
  void solve(vector<vector<int>>& ans, vector<int>& temp, vector<int>& cand, int tar, int ind){
    if(tar<0) return;
    if(tar==0){
      ans.push_back(temp);
      return;
    }
    for(int i=ind;i<cand.size();i++){
      temp.push_back(cand[i]);
      solve(ans, temp, cand, tar-cand[i], i);
      temp.pop_back();
    }
  }
    vector<vector<int>> combinationSum(vector<int>& cand, int tar) {
      vector<vector<int>> ans;
      vector<int> temp;
      solve(ans, temp, cand, tar, 0);
      return ans;
    }
};