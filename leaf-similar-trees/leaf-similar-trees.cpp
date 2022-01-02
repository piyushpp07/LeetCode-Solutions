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
    vector<int>tree;
    
    
private: 
    void helper(TreeNode *root)
    {
        if(root==nullptr)
            return ;
        if(root->left==nullptr&&root->right==nullptr)
            tree.push_back(root->val);
        helper(root->left);
        helper(root->right);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
      helper(root1);
     vector<int >tree1=tree;
        tree.clear();
      helper(root2);
      for(int i:tree)
          cout<<i<<" ";
        cout<<"\n";
      for(int j:tree1)
          cout<<j<<" ";
        if(tree1.size()==tree.size())
        {
        for(int i=0;i<tree1.size();i++)
        {
            if(tree1[i]!=tree[i])
                return false;
        }
        return true;
        }
        return false;
    }
};