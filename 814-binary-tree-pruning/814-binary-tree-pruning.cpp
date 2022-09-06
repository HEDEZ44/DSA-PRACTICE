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
  bool solve(TreeNode* root){
    if(!root) return false;
    if(!solve(root->right) and !solve(root->left) and root->val==0){
      root->left=NULL;
      root->right=NULL;
      return false;
    }
    if(!solve(root->left)){
      root->left=NULL;
    }
    if(!solve(root->right)){
      root->right=NULL;
    }
    return true;
  }
    TreeNode* pruneTree(TreeNode* root) {
      solve(root);
      if(!root->left && !root->right && root->val==0) return NULL;
      return root;
    }
};