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
    public:
        vector<int> rightSideView(TreeNode *root)
        {
            if(!root)
                    return {};
            queue<TreeNode*> q;
            q.push(root);
            vector<int> v;
            int i = 0, lvl = 0;
            while (!q.empty())
            {
                int n = q.size();
                for (int i = 0; i < n; i++)
                {
                    TreeNode *curr = q.front();
                    q.pop();
                    if (i == 0)
                        v.push_back(curr->val);
                    if (curr->right != NULL)
                        q.push(curr->right);
                    if (curr->left != NULL)
                        q.push(curr->left);
                }
            }
            return v;
        }
};