class Solution {
public:
  
  class TreeNode{
    public:
         TreeNode* next[2];
         TreeNode(){ next[0]=NULL; next[1]=NULL;} 
  };
  
  
  TreeNode* buildTree(vector<int>& nums){
    TreeNode* root= new TreeNode();
    TreeNode* curr;
    
    int n=nums.size();
    for(int i=0;i<n;i++){
      int num=nums[i];
      curr=root;
      
      for(int j=31;j>=0;j--){
        int idx=((num>>j) & 1);
        if(curr->next[idx]==NULL){
          curr->next[idx]= new TreeNode();
        }
        curr=curr->next[idx];
      }
    }
    return root;
  }
  
  
 int helper(TreeNode* curr, int num){
   int res=0;
   for(int i=31;i>=0;i--){
     int idx=((num>>i)&1) ? 0 : 1;
     if(curr->next[idx]){
       res<<=1;
       res|=1;
       curr=curr->next[idx];

     }
     else{
       res<<=1;
       res|=0;
       curr=curr->next[idx?0:1];
     }
   }
   return res;
 } 
  
  
    int findMaximumXOR(vector<int>& nums) {
      
      int ans=0;
      TreeNode* root= buildTree(nums);
      for(auto i:nums){
        ans=max(ans, helper(root,i));
      }
      return ans;
      
        
    }
};