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
    int ans = INT_MIN;
    int solve(TreeNode *root)
    {
        if(!root)
            return 0;
        int a = max(0,solve(root->left));
        int b = max(0,solve(root->right));
        int k = a+b +root->val;
        ans = max(k,ans);
        return max(a,b) + root->val;
    }
    int maxPathSum(TreeNode* root) {
       solve(root);
       return ans;
    
    }   
};