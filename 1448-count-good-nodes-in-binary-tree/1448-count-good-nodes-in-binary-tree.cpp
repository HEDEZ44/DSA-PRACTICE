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
private:
    int ans=0;
    void dfs(TreeNode* node,int maxi){
        if(node->val>=maxi) ans++;
        maxi=max(maxi,node->val);
        if(node->left!=NULL) dfs(node->left,maxi);
        if(node->right!=NULL) dfs(node->right,maxi);
    }
public:
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        dfs(root,root->val);  
        return ans;
    }
};