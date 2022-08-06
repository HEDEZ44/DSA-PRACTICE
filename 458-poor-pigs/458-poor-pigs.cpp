class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        
      int k=minutesToTest/minutesToDie + 1;
      int pigs=0;
      while(pow(k, pigs)<buckets) pigs++;
      return pigs;
    }
};