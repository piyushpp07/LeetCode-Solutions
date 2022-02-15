/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int ans = 0;
    
    public int maxDepth(TreeNode root) {
        solve(root,0);
        return ans;
    }
    public void solve(TreeNode root , int d)
    {
        if(root == null)
        {
            ans = Math.max(ans,d);
            return ;
        }
        solve(root.left,d+1);
        solve(root.right,d+1);
    }
}