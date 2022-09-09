class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](vector<int>& a, vector<int>& b){
          return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);
        });
      int n=properties.size()-1;
      int temp=INT_MIN, cnt=0;
      for(int i=n;i>=0;i--){
        if(temp>properties[i][1]) cnt++;
        temp=max(temp, properties[i][1]);
      }
      return cnt;
    }
};