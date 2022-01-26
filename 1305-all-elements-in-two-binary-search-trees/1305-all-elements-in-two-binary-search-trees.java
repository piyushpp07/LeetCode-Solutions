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
    public void traverse(PriorityQueue<Integer>pq,TreeNode n1)
    {
        if(n1==null)
        {
            return;
        }
        if(n1.left!=null)
        traverse(pq,n1.left);
        pq.add(n1.val);
        if(n1.right!=null)
        traverse(pq,n1.right);
    }
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer>res = new ArrayList<Integer>();
        PriorityQueue<Integer>pq=new PriorityQueue<>();
        traverse(pq,root1);
        traverse(pq,root2);
        while(pq.size()!=0)
        {
            res.add(pq.peek());
            pq.remove();
        }
        return res;
            
    }
}