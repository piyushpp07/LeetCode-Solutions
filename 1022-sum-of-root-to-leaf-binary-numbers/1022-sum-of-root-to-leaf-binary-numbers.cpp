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
int s=0;
     void sum(TreeNode *root ,int qsum )
    {
        if(root->left==nullptr&&root->right==nullptr)
        {
         s = s + qsum*2 + root->val ;
        }
        if(root->left!=nullptr)
            sum(root->left ,qsum*2 + root->val);
        if(root->right!=nullptr)
            sum(root->right,qsum*2 + root->val);
    }
public:
    
    int sumRootToLeaf(TreeNode* root) {
        sum(root,0);
        return s;
    }
};