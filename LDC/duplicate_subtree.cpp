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
  
  
  string duplicate(vector<TreeNode*>& res, unordered_map<string, int>& map, TreeNode* root){
    if(!root) return "";
    string temp=to_string(root->val)+","+ duplicate(res,map,root->left)+","+duplicate(res,map,root->right);
    if(map[temp]++ == 1) res.push_back(root);
    return temp;
  }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
      
      vector<TreeNode*> res;
      unordered_map<string, int> map;
      duplicate(res,map, root);
      return res;
        
    }
};



//     vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
//         unordered_map<string, int>m;
//         vector<TreeNode*>res;
//         DFS(root, m, res);
//         return res;
//     }
    
//     string DFS(TreeNode* root, unordered_map<string, int>& m, vector<TreeNode*>& res){
//         if(!root) return "";
//         string s = to_string(root->val) + "," + DFS(root->left, m, res) + "," + DFS(root->right, m, res);
//         if(m[s]++ == 1) res.push_back(root);
//         return s;
//     }
// };