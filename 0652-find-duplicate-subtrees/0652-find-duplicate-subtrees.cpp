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
    vector<TreeNode *>res;
    string dfs(TreeNode *root,map<string,int>&mp)
    {
        if(!root)
            return "";
        string curr = to_string(root->val) + "," + dfs(root->left,mp) + "," + dfs(root->right,mp);
         mp[curr]++;
        if(mp[curr] == 2)
        {
            res.push_back(root);
           
        }
        return curr;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string,int >mp;
        dfs(root,mp);
        return res;
    }
};