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
class Solution
{
public:
    TreeNode *createBinaryTree(vector<vector<int>> &d)
    {
        unordered_map<int, TreeNode *> Nodes;
        unordered_map<int, bool> isChild;

        for (auto it : d)
        {
            if (Nodes.count(it[0]) == 0)
            {
                TreeNode *par = new TreeNode(it[0]);
                Nodes[it[0]] = par;
            }
            if (Nodes.count(it[1]) == 0)
            {
                TreeNode *child = new TreeNode(it[1]);
                Nodes[it[1]] = child;
            }
            if (it[2])
                Nodes[it[0]]->left = Nodes[it[1]];
            else
                Nodes[it[0]]->right = Nodes[it[1]];
            isChild[it[1]] = true;
        }
        TreeNode *res;
        for (auto it : d)
        {
            if (isChild[it[0]] != true)
                res = Nodes[it[0]];
        }
        return res;
    }
};