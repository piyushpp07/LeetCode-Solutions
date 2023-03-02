class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX,i =0, n = nums.size(),j = 0,curr_sum = 0;
        while(j<n){
            while(j < n && curr_sum < target)
            {
                curr_sum += nums[j];
                j++;
            }
            
            while(i <= j && curr_sum >= target)
            {
                ans = min(j-i,ans);
                curr_sum -= nums[i++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};