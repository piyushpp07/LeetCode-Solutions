class Solution {
public:
    int solve(vector<int>&nums,int tar,int idx,vector<int>&dp)
    {
        if(idx == nums.size())
        {
            if(tar == 0)
            {
                return 1;
            }
            return 0;
        }
        //add
        int a = solve(nums,tar+nums[idx],idx+1,dp);
        //sub
        int b = solve(nums,tar-nums[idx],idx+1,dp);
        return a+b;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(nums,target,0,dp);
    }
};