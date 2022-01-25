class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
      
      
      if(arr.size()<3){
        return false;
      }
      int i,j;
      i=0;
      j=arr.size()-1;
      
      while(i<j){
        if(arr[i]<arr[i+1])
          i++;
        else if(arr[j-1]>arr[j])
          j--;
        else
          break;
      }
      
      if(i==j && j!=0 && i!=arr.size()-1)
        return true;
      return false;
      
        
    }
};