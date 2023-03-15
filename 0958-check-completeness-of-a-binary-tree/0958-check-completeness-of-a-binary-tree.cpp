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
    bool isCompleteTree(TreeNode* root) {
        bool pre = true;
        queue<TreeNode *>q;
        q.push(root);
        while(q.size()!=0)
        {
            TreeNode *curr = q.front();
            q.pop();
            if(curr == NULL)
                pre = false;
            else {
                if(pre == false)
                    return false;
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return true;
    }
};