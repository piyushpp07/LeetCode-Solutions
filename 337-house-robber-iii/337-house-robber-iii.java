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
    static  HashMap<TreeNode,Integer>hs = new HashMap<>();
      public int rob(TreeNode root) {
        return solve(root);
    }
    public int solve(TreeNode node)
    {   if(node==null)
        return 0;
        if(hs.containsKey(node))
            return hs.get(node);
        int steal = 0;
        if(node.left!=null){
          steal += solve(node.left.left)+solve(node.left.right);
   
        }
        if(node.right!=null){
         steal +=  solve(node.right.left)+solve(node.right.right); 
        }
 
        int notsteal  = solve(node.left)+solve(node.right);
        hs.put(node,Math.max(node.val+steal,notsteal));
        return hs.get(node);
    }
}