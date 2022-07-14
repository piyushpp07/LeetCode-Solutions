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
        map<int, int> mp;
    void findPos(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
            mp[arr[i]] = i;
    }
    TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int &index, int instart, int inend, int n)
    {
        if (index >= n || instart > inend)
            return NULL;
        int ele = preorder[index++];
        TreeNode *root = new TreeNode(ele);
        int pos = mp[ele];

        root->left = solve(preorder, inorder, index, instart, pos - 1, n);
        root->right = solve(preorder, inorder, index, pos + 1, inend, n);
        return root;
    }
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        int index = 0;
        findPos(inorder);
        return solve(preorder, inorder, index, 0, n - 1, n);
    }
};