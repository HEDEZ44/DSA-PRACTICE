class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> temp;
        vector<int> tmp(2,0);
        for (int i = 0; i < n; i++) {
            tmp[0] = speed[i];
            tmp[1] = efficiency[i];
            temp.push_back(tmp);
        }
      priority_queue<int, vector<int>, greater<int>> heap;
      sort(temp.begin(), temp.end(), [](vector<int>& a, vector<int>& b){
        return a[1]>b[1];
      });
      long mini=0, total=0;
      long res=0;
      for(int i=0;i<k;i++){
        total+=temp[i][0];
        mini=temp[i][1];
        res= max(res, total*mini);
        heap.push(temp[i][0]);
      }
      for(int i=k;i<n;i++){
        if(temp[i][0]>heap.top()){
          total+=(-heap.top() + temp[i][0]);
          mini=temp[i][1];
          res=max(res, total*mini);
          heap.pop();
          heap.push(temp[i][0]);
        }
      }
      return (int)(res%1000000007);
    }
};