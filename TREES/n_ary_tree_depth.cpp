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
    int maxDepth(Node* root) {
      if(root ==NULL)
        return 0;
      int md=0;
      for(int i=0;i< root->children.size();i++){
        md = max(md,maxDepth(root->children[i]));
      }
      return md +1;
        
    }
};