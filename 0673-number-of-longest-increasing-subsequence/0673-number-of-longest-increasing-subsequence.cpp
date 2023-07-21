class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
                   vector<int> dp(nums.size(), 1),cnt(nums.size(),1);
            int maxi = 1;
            map<int, int> mp;
            for (int i = 0; i < nums.size(); i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (nums[j] < nums[i])
                    {
                        if (dp[i] < dp[j] + 1)
                        {
                            dp[i] = dp[j] + 1;
                            cnt[i] = cnt[j];
                            maxi = max(dp[i], maxi);
                        }
                        else if (dp[i] == dp[j] + 1)
                            cnt[i] += cnt[j];
                    }
                }
            }
            int ans = 0;
            for(int i= 0;i<nums.size();i++)
            {
                if(dp[i] == maxi)
                    ans+=cnt[i];
            }
            return ans;
    }
};