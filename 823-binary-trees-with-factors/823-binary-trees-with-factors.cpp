class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long ans=0, Mod=1e9 + 7;
        sort(arr.begin(), arr.end());
        unordered_map<int, long> M;
        for(int i=0;i<arr.size();i++){
          M[arr[i]]=1;
          for(int j=0;j<i;j++){
            if(arr[i]%arr[j]==0){
              M[arr[i]]+= (M[arr[j]]*M[arr[i]/arr[j]]);
            }
          }
          ans= (ans + M[arr[i]])%Mod;
        }
       return ans; 
    }
};