class Solution {
    public List<List<Integer>> ans = new ArrayList<>();
    public List<List<Integer>> permute(int[] nums) {
       List<Integer>que = new ArrayList<>();
       solve(nums,que);
      return ans;
    }
    public void solve(int []nums,List<Integer>que)
    {
        if(que.size()==nums.length)
        {
         ans.add(new ArrayList(que));
            return ;
        }

        for(int i : nums)
        {
            if(que.contains(i)) continue;
            else {
                que.add(i);
                solve(nums,que);
                que.remove(que.size()-1);
            }
            
        
           
        }
    }
}