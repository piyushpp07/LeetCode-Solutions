class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n,INT_MAX),suff(n,INT_MIN);
        int maxi = nums[0];
        for(int i = 0;i<n;i++)
        {
            suff[i] = max(maxi,nums[i]);
            maxi = max(nums[i],maxi);
        }
        int mini = nums[n-1];
        for(int i = n - 1;i>=0;i--)
        {
            pre[i] = min(nums[i],mini);
            mini = min(nums[i],mini);
        }
        int ans =0;
        for(int i = 1;i<n-1;i++)
        {
            if(pre[i+1]>nums[i] && suff[i-1]<nums[i])
                ans += 2;
            else if(nums[i]>nums[i-1] && nums[i+1]>nums[i])
                ans += 1;
        }
        return ans;
    }
};