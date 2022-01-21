class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int s=gas.size();
      int total_diff=0;
      int curr_diff=0;
      int pos=0;
      for(int i=0;i<s;i++){
        total_diff+=gas[i]-cost[i];
        curr_diff+=gas[i]-cost[i];
        if(curr_diff<0){
          curr_diff=0;
          pos=i+1;
        }
      }
      return (total_diff) < 0 ? -1 : pos;
        
    }
};