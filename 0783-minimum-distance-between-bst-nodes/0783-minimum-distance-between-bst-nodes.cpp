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
    vector<int>v;
    int  ans = INT_MAX;
    void solve(TreeNode * root)
    {
        if(!root)
            return ;
        int a = INT_MAX,b = INT_MAX;
        v.push_back(root->val);
        solve(root->left);
        solve(root->right);
        
        
    }
    int minDiffInBST(TreeNode* root) {
        solve(root);
       sort(v.begin(),v.end());
        for(int i =0;i<v.size()-1;i++)
        {
            ans = min((v[i+1]-v[i]),ans);
        }
        return ans;
    }
};