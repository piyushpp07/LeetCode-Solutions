/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        void inorder(TreeNode *node, vector<int> &vals)
        {
            if (!node)
                return;
            inorder(node->left, vals);
            vals.push_back(node->val);
            inorder(node->right, vals);
        }
    TreeNode* increasingBST(TreeNode *root)
    {
        vector<int> vals;
        inorder(root, vals);
        TreeNode *ans = new TreeNode(0);
        TreeNode *cur = ans;
        for (int v: vals)
        {
            cur->right = new TreeNode(v);
            cur = cur->right;
        }
        return ans->right;
    }
};