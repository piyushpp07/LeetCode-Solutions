class Solution {
private:
    int solve(vector<int>&nums,int i,int ispos,vector<vector<int>>&dp)
    {
        if(i==nums.size())
            return 0;
        if(dp[i][ispos]!=-1)
            return dp[i][ispos];
        int s1 = 0, s2 = 0;
        if(ispos == 1)
        {
            if(nums[i]-nums[i-1]>0)
            {
                s1 = solve(nums,i+1,1-ispos,dp)+1;
            }
        }
        if(ispos == 0)
        {
            if(nums[i]-nums[i-1]<0)
            {
                s1 = solve(nums,i+1,1-ispos,dp)+1;
            }     
        }
        s2 = solve(nums,i+1,ispos,dp);
        return dp[i][ispos] = max(s1,s2);
    }
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(2,-1));
        int p = solve(nums,1,1,dp);
        int n = solve(nums,1,0,dp);
        return max(p,n)+1;
    }
};