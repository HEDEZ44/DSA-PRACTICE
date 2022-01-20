class MyQueue {
  stack<int> s;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
      s.push(x);
        
    }
    
    int pop() {
      if(s.empty())
        return 0;
      int x=s.top();
      s.pop();
      if(s.empty())
        return x;
      int item=pop();
      s.push(x);
      return item;
        
    }
    
    int peek() {
      if(s.empty())
        return 0;
      int x=s.top();
      s.pop();
      if(s.empty()){
        s.push(x);
        return x;
      }
      int item=peek();
      s.push(x);
      return item;
    }
    
    bool empty() {
      if(s.empty())
        return true;
      return false;
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */