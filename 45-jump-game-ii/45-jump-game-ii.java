class Solution {
    public int helper(int[]nums,int i,int[] dp)
    {   
        if(i>nums.length-1)
            return 400000;
        if(i==nums.length-1)return 0;
        if(dp[i]!=-1)
            return dp[i];
        int maxans = 400000;
        for(int j=1;j<=nums[i];j++)
        {   
            int q = helper(nums,i+j,dp);
            maxans=Math.min(maxans,q);
        }
        return dp[i] = maxans+1;
    }
    public int jump(int[] nums) {
        int []dp=new int[nums.length];
        for(int i=0;i<nums.length;i++)
        {
            dp[i]=-1;
        }
        return helper(nums,0,dp);
    }
}