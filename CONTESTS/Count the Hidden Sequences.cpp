class Solution {
public:
    int numberOfArrays(vector<int>& d, int lower, int upper) {
      
      long sum=0;
      long mn=0;
      long mx=0;
      for(int i=0;i<d.size();i++){
        sum+=d[i];
        mn=min(mn,sum);
        mx=max(mx,sum);
      }
      long count=(upper-mx)-(lower-mn)+1;
      if(count>0)
        return count;
      return 0;
        
    }
};

// long sum = 0, mn = 0, mx = 0;
//         for (int n : A) {
//             sum += n;
//             mn = min(mn, sum);
//             mx = max(mx, sum);
//         }
//         return max(0L, mn - mx + upper - lower + 1);