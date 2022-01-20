class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
      
      int low=1;
      int high=INT_MIN;
      for(auto pile:piles){
        high=max(high,pile);
      }
      while(low<high){
        
        int mid=(low+high)/2;
        int val=0;
        for(auto i:piles){
          val+=(mid+i-1)/mid;
        }
        if(val>h)
          low=mid+1;
        else
          high=mid;
      }
      return low;
        
    }
};