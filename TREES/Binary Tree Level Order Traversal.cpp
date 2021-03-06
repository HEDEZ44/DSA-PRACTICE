/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  void levelorder(TreeNode* root, vector<vector<int>>& levels){
    
    if(root == NULL)
      return;
    
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    vector<int> v;
    while(!q.empty()){
      TreeNode* node= q.front();
      
      q.pop();
      if(node != NULL){
        
        v.push_back(node->val);
        cout<<node->val;
        if(node->left)
          q.push(node->left);
        if(node->right)
          q.push(node->right);
      }
      else if(!q.empty())
        q.push(NULL);
      
      if(node == NULL){
        levels.push_back(v);
        v.clear();
      }
    }
    
  }
  
  
    vector<vector<int>> levelOrder(TreeNode* root) {
        
      vector<vector<int>> levels;
      levelorder(root, levels);
      return levels;
    }
};