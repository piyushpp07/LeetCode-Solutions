/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<double> averageOfLevels(TreeNode *root)
        {
            queue<TreeNode*> q;
            q.push(root);
            vector<double> v;
            while (!q.empty())
            {
                int n = q.size();
                double ans = 0;
                for (int i = 0; i < n; i++)
                {
                    TreeNode *a = q.front();
                    q.pop();
                    ans += a->val;
                    if (a->left)
                        q.push(a->left);
                    if (a->right)
                        q.push(a->right);
                }
                v.push_back((ans) / n);
            }
            return v;
        }
};