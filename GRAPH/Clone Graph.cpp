

class Solution { 
public:
  void dfs(Node* curr, Node* node, vector<Node*>& vis){
    vis[node->val]=node;
    for(auto ele:curr->neighbors){
      if(vis[ele->val]==NULL){
        Node* newNode= new Node(ele->val);
        node-> neighbors.push_back(newNode);
        dfs(ele, newNode, vis);
      }
      else node-> neighbors.push_back(vis[ele->val]);
    }
  }
    Node* cloneGraph(Node* node) {
      if(node==NULL) return NULL;
        vector<Node*> vis(101,NULL);
        Node* copy= new Node(node->val);
        vis[node->val]= copy;
        for(auto ele:node->neighbors){
          if(vis[ele->val]==NULL){
            Node* nbs=new Node(ele->val);
            copy->neighbors.push_back(nbs);
            dfs(ele, nbs, vis); 
          }
          else copy->neighbors.push_back(vis[ele->val]); 
        }
      return copy;
    }
};