class UnionFind{
  vector<int> parent, size;
  public:
    UnionFind(int n){
      parent.resize(n), size.resize(n);
      for(int i=1;i<n;i++){
        parent[i]=i, size[i]=1;
      }
    }
   int find(int x){
     if(parent[x]==x) return x;
     return parent[x]=find(parent[x]);
   }
  bool Union(int u, int v){
    int pv=find(v), pu=find(u);
    if(pv == pu) return false;
    else if(size[pv]>size[pu]){
      size[pv]+=size[pu];
      parent[pu]=pv;
    }
    else{
      size[pu]+=size[pv];
      parent[pv]=pu;
    }
    return true;
  }
  
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        UnionFind uf(n);
        for(auto it:edges){
          if(!uf.Union(it[0], it[1])) return {it[0], it[1]};
        }
      return {};
    }
};