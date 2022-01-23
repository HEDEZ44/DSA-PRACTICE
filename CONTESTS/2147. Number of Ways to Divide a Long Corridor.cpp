class Solution {
public:
    int numberOfWays(string c) {
      int seats=0;
      for(int i=0;i<c.length();i++){
        if(c[i]=='S'){
          seats++;
        }
      }
      if(seats==0 || seats%2) return 0;
      
      
      int cnt=0;
      long long ans=1;
      for(int i=0;i<c.length();i++){
        if(c[i]=='S')
          cnt++;
        if(cnt==2){
          int p=1;
          i++;
          while(i<c.length() && c[i]=='P'){
            p++;
            i++;
          }
          if(i==c.length()) break;
          ans=(ans*p)%(1000000007);
          i--;
          cnt=0;
        }
          
      }
      return ans;
        
    }
};