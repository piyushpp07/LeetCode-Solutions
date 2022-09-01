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
    int cnt = 0;
    void f(TreeNode* root,int maxi)
    {
        if(!root)
            return ;
        int ans = root->val;
        if(ans >= maxi)
            cnt++,maxi  =  max(ans,maxi);
        if(root->left)
            f(root->left,maxi);
        if(root->right)
            f(root->right,maxi);
            
    }
    int goodNodes(TreeNode* root) {
        f(root,INT_MIN);
        return cnt;
    }
};