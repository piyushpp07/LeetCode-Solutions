/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans ;
    void find(TreeNode *root,TreeNode * target,TreeNode *orignal)
    {
        if(!root)
            return ;
        if(orignal == target)
            ans = root;
        if(root->left)
           find(root->left,target,orignal->left);
        if(root->right)
           find(root->right,target,orignal->right);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        find(cloned,target,original);
        return ans;
    }
};