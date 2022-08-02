class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
      int n=mat.size();
      int left=mat[0][0], right=mat[n-1][n-1];
      int mid=0;
      while(left<right){
        mid=left + (right-left)/2;
        int num=0;
        for(int i=0;i<n;i++){
          int pos=upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
          num+=pos;
        }
        if(num<k) left=mid+1;
        else right=mid;
      }
      return left;
    }
};