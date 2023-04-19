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
    int ans = 0;
    
    void  solve(TreeNode *root,int curr,int d)
    {
        if(!root)
            return ;
        ans = max(curr,ans);
        if(d == 1)
        {
            if(root->left)
            {
              solve(root->left,curr+1,0); 
            }
             solve(root->right,1,1);
        }
        else if(d ==0 ){
            if(root->right)
            {
             solve(root->right,curr+1,1);  
            }

               solve(root->left,1,0);
        }
    }
    int longestZigZag(TreeNode* root) {
        solve(root->left,1,0);
        solve(root->right,1,1);
        return ans;
    }
};