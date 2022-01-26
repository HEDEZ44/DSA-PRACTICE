class Solution {
public:
  
  
  void postorder(TreeNode* root, vector<int>& v){
    if(root==NULL){
      return;
    }
    postorder(root->left, v);
    postorder(root->right, v);
    v.push_back(root->val);
  }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
      
      vector<int> v;
      
      postorder(root1,v);
      postorder(root2,v);
      sort(v.begin(), v.end());
      return v;
      
      
        
    }
};

//Redo it using depth first search;