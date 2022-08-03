class MyCalendar {
public:
  vector<pair<int, int>> nums;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it:nums){
          if(max(it.first, start)<min(it.second, end)) return false;
        }
      nums.push_back({start, end});
      return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */