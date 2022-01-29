class Solution {
public:
  vector<int> NSL( vector<int> h, int n){
    int pseudoidx=-1;
    vector<int> left;
    stack<pair<int,int>> s;
    
    for(int i=0;i<n;i++){
      if(s.size()==0){
        left.push_back(pseudoidx);
        s.push({h[i],i});
      }
      else if(s.size()>0 && s.top().first<h[i]){
        left.push_back(s.top().second);
        s.push({h[i],i});
      }
      else if(s.size()>0 && s.top().first>=h[i]){
        while(s.size()>0 && s.top().first>=h[i]){
          s.pop();
        }
        if(s.size()==0){
          left.push_back(pseudoidx);
          s.push({h[i],i});
        }
        else{
          left.push_back(s.top().second);
          s.push({h[i],i});
        }
        
      }
    }
    return left;
  }
  
    vector<int> RSL( vector<int> h, int n){
    int pseudoidx=n;
    vector<int> right;
    stack<pair<int,int>> s;
    
    for(int i=n-1;i>=0;i--){
      if(s.size()==0){
        right.push_back(pseudoidx);
        s.push({h[i],i});
      }
      else if(s.size()>0 && s.top().first<h[i]){
        right.push_back(s.top().second);
        s.push({h[i],i});
      }
      else if(s.size()>0 && s.top().first>=h[i]){
        while(s.size()>0 && s.top().first>=h[i]){
          s.pop();
        }
        if(s.size()==0){
          right.push_back(pseudoidx);
          s.push({h[i],i});
        }
        else{
          right.push_back(s.top().second);
          s.push({h[i],i});
        }
        
      }
    }
    reverse(right.begin(),right.end());
      return right;
  }
  
  

  
    int largestRectangleArea(vector<int>& h) { 
      stack<pair<int,int>> s;
      int n=h.size();
      
      
      vector<int> left= NSL(h,n);
      vector<int> right= RSL(h,n);
      int maxArea=0;
      for(int i=0;i<n;i++){
        maxArea=max(maxArea, (right[i]-left[i]-1)*h[i]);
      }
     
      
      return maxArea;
        
    }
};