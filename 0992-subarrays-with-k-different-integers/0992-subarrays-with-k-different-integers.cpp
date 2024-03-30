class Solution {
public:
    int solve(vector<int>&nums,int k)
    {
        int i = 0,j = 0,n = nums.size(),ans =0;
        unordered_map<int,int>mp;
        while(j < n)
        {
            mp[nums[j]]++;
            while( mp.size() > k)
            {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
                            
            ans += (j - i + 1);
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};