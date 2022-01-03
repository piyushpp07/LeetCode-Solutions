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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        vector<vector<int>>v;
        if(!root)
            return v;
        int level=1;
        while(q.size()>0)
        {
            int n=q.size();
            vector<int>a;
            for(int i=0;i<n;i++)
            {
                TreeNode* top=q.front();
                q.pop();
                a.push_back(top->val);
                if(top->left!=nullptr)
                    q.push(top->left);
                if(top->right!=nullptr)
                    q.push(top->right);
            }
            if(level%2==0)
            {  reverse(a.begin(),a.end());
                v.push_back(a);
            }
                else
                v.push_back(a);
            level++;
        }
        return v;
    }
};