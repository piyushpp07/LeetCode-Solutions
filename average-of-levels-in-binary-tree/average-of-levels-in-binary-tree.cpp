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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>v;
        if(!root)
            return v;
        queue<TreeNode *>q;
        q.push(root);
        int level=0;
        while(q.size()>0)
        {
            int n=q.size();
            vector<int>ans;
            double solve=0;
            int si=0;
            for(int i=0;i<n;i++)
            {
                TreeNode * top=q.front();
                q.pop();
                solve+=top->val;
                si++;
                if(top->left!=nullptr)
                    q.push(top->left);
                if(top->right!=nullptr)
                    q.push(top->right);
            }
            if(si>0)
            v.push_back(solve/si);
        }

        return v;
    }
};