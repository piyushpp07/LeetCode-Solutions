using lli = long long int;
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        lli lo = 0,hi = 0;
        for(auto i : nums)
        {
            lo = max(lo,(lli)i);
            hi  += i;
        }
        lli ans =INT_MAX;
        while(lo<=hi)
        {
            lli mid  = lo + (hi - lo)/2;
            lli cnt = 1,sum =0;
            for(int i =0;i<nums.size();i++)
            {
                sum += nums[i];
                if(sum > mid)
                {
                    sum = nums[i];
                    cnt++;
                }
            }
            if(cnt > k){
                lo = mid +1 ;
            }  
            else {
                hi= mid - 1,ans = mid;
            }
                
        }
        return ans;
    }
};