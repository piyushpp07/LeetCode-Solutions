class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans(n,-1);
        if(n<2*k+1)
            return ans;
        int p = 0, q = 0, r = k;
        long long sum = 0;
        while(r<n)
        {
            if(q>=k)
            {
                sum+=nums[r];
            }
            while(q<k)
            {
                sum+=nums[q++];
                sum+=nums[r++];
            }
            if(q == k&& k!=0)
            {
                sum+=nums[r];
            }
            ans[q] = sum/(2*k+1);
            r++;
            q++;
            sum-=nums[p++];
        }
        return ans;
    }
};