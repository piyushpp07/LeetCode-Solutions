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
    
    private:
    void traverse(vector<int>&v,TreeNode* n1)
    {
  if(!n1)
        {
            return;
        }
        v.push_back(n1->val);
        cout<<n1->val;
        if(n1->left)
        traverse(v,n1->left);

        if(n1->right)
        traverse(v,n1->right);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>pq;
        traverse(pq,root1);
        traverse(pq,root2);
        sort(pq.begin(),pq.end());
        return pq;
    }
};