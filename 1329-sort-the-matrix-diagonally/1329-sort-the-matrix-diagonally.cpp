class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
      int n=mat.size();
      int m=mat[0].size();
      for(int l=0;l<m;l++){
        vector<int> temp;
        for(int i=0, j=l; i<n && j<m; i++, j++){
          temp.push_back(mat[i][j]);
        }
        sort(temp.begin(), temp.end());
        int k=0;
        for(int i=0, j=l; i<n && j<m; i++, j++){
          mat[i][j]=temp[k++];
        }
      }
      for(int l=1;l<n;l++){
        vector<int> temp;
        for(int j=0, i=l; j<m && i<n; j++, i++){
          temp.push_back(mat[i][j]);
        }
        sort(temp.begin(), temp.end());
        int k=0;
        for(int j=0, i=l; j<m && i<n; j++, i++){
          mat[i][j]=temp[k++];
        }
      }
      return mat;
    }
};