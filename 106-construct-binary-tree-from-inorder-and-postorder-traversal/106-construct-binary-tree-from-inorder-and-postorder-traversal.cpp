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
    map<int, int> mp;
    TreeNode* solve(vector<int> &post, int pos, int poe, vector<int> &in, int ins, int ine)
    {
        if (pos > poe || ins > ine)
            return NULL;
        int ele = post[poe];
        TreeNode *root = new TreeNode(ele);
        int inindex = mp[ele];
        int noele = inindex - ins - 1;
        root->left = solve(post, pos, pos + noele, in, ins, ins + noele);
        root->right = solve(post, pos + noele + 1, poe - 1, in, ins + noele + 2, ine);
        return root;
    }
    public:
        TreeNode* buildTree(vector<int> &in, vector<int> &po)
        {
            int n = po.size();
            for (int i = 0; i < in .size(); i++)
                mp[ in[i]] = i;
            return solve(po, 0, n - 1, in, 0, n - 1);
        }
};