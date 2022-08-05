class Solution {
public:
    int dp[10001];
    int solve(vector<int>&nums,int target,int sum)
    {
        if(target == sum)
        {
            return 1;
        }
        if(target<sum)
            return 0;
        if(dp[sum]!=-1)
            return dp[sum];
        int a = 0;
        for(int i = 0;i<nums.size();i++){
            if(target>=nums[i])
            {
                a += solve(nums,target,sum+nums[i]);
            }
        }
        return dp[sum]=a;

    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        memset(dp,-1,sizeof dp);
        return solve(nums,target,0);
    }
};