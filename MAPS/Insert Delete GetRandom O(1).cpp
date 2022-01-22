class RandomizedSet {
  unordered_map< int , int > mp;
  vector<int> v;
  
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end()){
          mp[val]=1;
          v.push_back(val);
          return true;
        }
      
      return false;
    }
    
    bool remove(int val) {
      
      if(mp.find(val)==mp.end())
        return false;
      auto it=find(v.begin(),v.end(),val);
        if(it!=v.end())
          v.erase(it);
      mp.erase(val);
      return true;
        
    }
    
    int getRandom() {
      
      
      return v[rand()%v.size()];
      
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */