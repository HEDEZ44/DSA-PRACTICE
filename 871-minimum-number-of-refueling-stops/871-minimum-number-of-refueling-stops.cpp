class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& s) {
      priority_queue<int> q;
      int n=s.size(), ans=0;
      for(int i=0;i<n;i++){
        while(startFuel<s[i][0] && !q.empty()){
          startFuel+=q.top();
          q.pop();
          ans++;
        }
        if(startFuel<s[i][0]) return -1;
        q.push(s[i][1]);
      }
      while(startFuel<target && !q.empty()){
        startFuel+=q.top();
        q.pop();
        ans++;
      }
      if(startFuel<target) return -1;
      return ans;
    }
};