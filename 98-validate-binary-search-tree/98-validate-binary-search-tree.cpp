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
    bool valid(TreeNode* root, long long Min, long long Max){
      if(!root) return true;
      if(root->val<=Min || root->val>=Max) return false;
      return valid(root->left, Min, root->val) && valid(root->right, root->val, Max);
      
    }
    bool isValidBST(TreeNode* root) {
        
        return valid(root, LLONG_MIN, LLONG_MAX);
    }
};