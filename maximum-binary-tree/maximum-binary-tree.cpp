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
    private: TreeNode* tree(vector<int>&nums,int q,int j)
    {   if(q>j)
        return 0;
        int m=INT_MIN,index=-1;
        int n=nums.size();
        for(int i=q;i<=j;i++)
        {
            if(m<nums[i])
            {
                m=nums[i];
                index=i;
            }
        }
        TreeNode* res = new TreeNode(m);

        res->left=tree(nums,q,index-1);
    
        res->right=tree(nums,index+1,j);
        
        return res;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return tree(nums,0,nums.size()-1);

    }
};