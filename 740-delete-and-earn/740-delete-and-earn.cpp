
class Solution {
private:
    int solve(vector<int>&nums,int idx,vector<int>&dp)
    {
       if(idx >= nums.size())
           return 0;
       if(dp[idx]!=-1)
           return dp[idx];
       int fidx = nums[idx];
       int ans1 = idx*fidx+solve(nums,idx+2,dp);
       int ans2 = solve(nums,idx+1,dp);
       return dp[idx]=max(ans1,ans2);
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxx = INT_MIN;
        for(int i = 0;i<nums.size();i++)
        {
            maxx = max(nums[i],maxx);
        }
        vector<int>freq(maxx+1,0);
        for(int i = 0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        vector<int>dp(maxx+1,-1);
        return solve(freq,0,dp);
        
    }
};