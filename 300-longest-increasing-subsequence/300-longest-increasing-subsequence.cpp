class Solution {

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,INT_MAX);
        dp[0]=INT_MIN;
        for(int i = 0;i<n;i++)
        {
            int j = upper_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
            if(dp[j-1]<nums[i]&&nums[i]<dp[j]){
                dp[j]=nums[i];
            }
        }
        int ans = 0;
        for(int i = 0;i<dp.size();i++)
        {
            if(dp[i]<INT_MAX)
                ans = i;
        }
        return ans;
    }
};