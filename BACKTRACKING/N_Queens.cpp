class Solution {
public:
  
  bool isSafe(vector<string>& v, int row, int col, int n){
    
    for(int i=row-1,j=col;i>=0;i--){
      if(v[i][j]=='Q')
        return false;
    }
    for(int i=row-1, j=col-1;i>=0 && j>=0;i--,j--){
      if(v[i][j]=='Q')
        return false;
    }
    for(int i=row-1, j=col+1; i>=0 && j<n;i--,j++){
      if(v[i][j]=='Q')
        return false;
    }
    return true;
}
    
   void nqueen(vector<vector<string>>& ans, vector<string>& v, int row, int n){
    
  if(row==n){
    ans.push_back(v);
    return;
  }
  
  for(int i=0;i<n;i++){
    
    if(isSafe(v,row,i,n)){
      v[row][i]='Q';
      nqueen(ans,v,row+1,n);
      v[row][i]='.';
    }
    
    
  }
  
  
}
  
  
  
    vector<vector<string>> solveNQueens(int n) {
      
      vector<string> v;
      for(int i=0;i<n;i++){
         string str;
        for(int j=0;j<n;j++){
          str+='.';
        }
        v.push_back(str);
      }
      vector<vector<string>> ans;
      int row=0;
      nqueen(ans,v,row,n);
      return ans;
        
    }
};