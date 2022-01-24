class Solution {
public:
    long long divide(long long dividend, long long divisor) {
      if(dividend==INT_MIN && divisor==-1)
        return INT_MAX;
      else if(dividend==INT_MAX && divisor==1)
        return INT_MAX;
      else if(dividend==INT_MIN && divisor==1)
        return INT_MIN;

      long long n1,n2;  
      if(dividend<0){
        n1=-dividend;
      }
      else
        n1=dividend;
      
      
      if(divisor<0){
        n2=-divisor;
      }
      else
        n2=divisor;
      
      
      long long ans=0;
      while(n1-n2>=0){
        int x=0;
        while((n1-((n2<<1)<<x)) >=0){
          x++;
        }
        ans+=1<<x;
        n1-=n2<<x;
      }
      if(dividend<0 ^ divisor<0)
        return -ans;
      return ans;
        
    }
};