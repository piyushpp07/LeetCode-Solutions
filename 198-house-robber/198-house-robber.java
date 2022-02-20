class Solution {
    public int rob(int[] nums) {
        int []dp = new int[nums.length];
        for(int i =0;i<nums.length;i++)
            dp[i]=-1;
        return solve(nums,dp,0);
    }
    public int solve(int []nums,int []dp,int i)
    {

        if(i>=nums.length)
        {
            return 0;
        }
        else if(dp[i]!=-1)
            return dp[i];
        else{
            int a = nums[i] + solve(nums,dp,i+2);
            int b = solve(nums,dp,i+1);
            return dp[i] = Math.max(a,b);
        }
    }
}