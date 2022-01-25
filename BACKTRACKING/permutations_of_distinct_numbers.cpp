void solve(vector<int> &A, vector<vector<int>>& ans, int idx){

    if(idx==A.size()){
        ans.push_back(A);
        return;
    }

    for(int i=idx;i<A.size();i++){
        swap(A[idx], A[i]);
        solve(A,ans,idx+1);
        swap(A[idx],A[i]);
    }



}


vector<vector<int> > Solution::permute(vector<int> &A) {

    vector<vector<int>> ans;

    solve(A,ans,0);

    return ans;



}
