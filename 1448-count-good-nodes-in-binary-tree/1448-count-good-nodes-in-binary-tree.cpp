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
  void solve(TreeNode* node, int left, int right, int &ans){
    if(!node) return;
    if(node->val>=left && node->val>=right){
      right=node->val;
      ans++;
    }
    solve(node->left, left, right, ans);
    solve(node->right, left, right, ans);
  }
    int goodNodes(TreeNode* root) {
      int left=root->val;
      int right=INT_MIN;
      int ans=1;
      solve(root->left, left, right, ans);
      solve(root->right, left, right, ans);
      return ans;
    }
};