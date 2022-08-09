class Solution {
public:
    unordered_set<int> S;
    unordered_map<int, long long> M;
    
    long long solve(int node){
      if(M.count(node)) return M[node];
      long long cnt=1;
      for(auto it:S){
        if(node%it==0 && S.count(node/it)){
          cnt+=solve(it)*solve(node/it);
        }
      }
      return M[node]=cnt;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        
        S.insert(arr.begin(), arr.end());
        long long ans=0;
        for(auto it:S){
          ans+=solve(it);
        }
        return int(ans%1000000007);
    }
};