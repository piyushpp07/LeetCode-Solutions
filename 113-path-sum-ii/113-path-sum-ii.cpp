/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    private:
        vector<vector < int>> v;
    void solve(TreeNode *root, int target, vector<int> &a, int sum)
    {
        if (!root)
            return;
        int curr = root->val + sum;
        a.push_back(root->val);
        if (curr == target && root->left == nullptr && root->right == nullptr)
        {
            v.push_back(a);
        }
        solve(root->left, target, a, curr);
        solve(root->right, target, a, curr);
        a.pop_back();
    }

    public:
        vector<vector < int>> pathSum(TreeNode *root, int targetSum)
        {
            vector<int> a;
            solve(root, targetSum, a, 0);
            return v;
        }
};