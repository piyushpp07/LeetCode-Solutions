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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>v;
        if(!root)
            return v;
        queue<TreeNode *>q;
        q.push(root);
        while(q.size()>0)
        {
            int n=q.size();
            vector<int>ans;
            for(int i=0;i<n;i++)
            {
                TreeNode * top=q.front();
                q.pop();
                ans.push_back(top->val);
                if(top->left!=nullptr)
                    q.push(top->left);
                if(top->right!=nullptr)
                    q.push(top->right);
            }
            v.push_back(ans);
        }
        int n=v.size();
        vector<vector<int>>arr;
        for(int i=n-1;i>=0;i--)
        {
            arr.push_back(v[i]);
        }
        return arr;
    }
};