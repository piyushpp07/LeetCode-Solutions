/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        TreeNode* solve(vector<int> nums, int lo, int hi)
        {
            if (lo <= hi)
            {
                int mid = (lo+hi)/2;
                TreeNode *a = new TreeNode(nums[mid]);
                a->left = solve(nums, lo, mid-1);
                a->right = solve(nums, mid + 1, hi);
                return a;
            }
            else
                return NULL;
        }
    TreeNode* sortedArrayToBST(vector<int> &nums)
    {
        int lo = 0, hi = nums.size();
        return solve(nums, 0, hi - 1);
    }
};