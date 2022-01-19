/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
  vector<int> pre(Node* root, vector<int>& v){
    
    if(root==NULL){
      return v;
    }
    
    v.push_back(root->val);
    cout<<root->val<<" ";
    int s=root->children.size();
    for(int i=0;i<s;i++){
      pre(root->children[i],v);
    }
    return v;
      
    
  }
    vector<int> preorder(Node* root) {
      
      vector<int> v;
      
      
      return pre(root,v);
        
    }
};