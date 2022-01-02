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
    private :
    int height(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        return max(height(root->left),height(root->right))+1;
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int lastlevel=height(root);
        int sum=0;
        queue<TreeNode *>q;
        q.push(root);
        while(q.size())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode *top=q.front();
                q.pop();
                if(lastlevel==1)
                    sum+=top->val;
               if(top->left!=nullptr)
                   q.push(top->left);
                if(top->right!=nullptr)
                    q.push(top->right);
            }
            lastlevel--;
        }
        return sum;
        
    }
};