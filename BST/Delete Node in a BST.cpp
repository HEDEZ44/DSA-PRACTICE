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
    TreeNode* deleteNode(TreeNode* root, int key) {
      if(root==NULL) return root;
      
      if(root->val==key){
        if(root->right){
        TreeNode* l=root->left;
        TreeNode* r=root->right;
        TreeNode* temp=r;
        while(temp->left!=NULL) temp=temp->left;
        temp->left=l;
        return r;
        }
        else{
          return root->left;
        }
        
      }
      if(root->val>key){
        root->left=deleteNode(root->left, key);
      }
      else root->right=deleteNode(root->right, key);
      
      return root;
        
    }
};