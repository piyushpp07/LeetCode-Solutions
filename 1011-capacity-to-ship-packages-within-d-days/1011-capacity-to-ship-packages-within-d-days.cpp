using lli = long long int;
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        lli lo =0,hi = 0;
        for(auto i : weights)
        {
            lo = max(lo,(lli)i);
            hi += i;
        }
        lli ans = 0;
        while(lo<=hi)
        {
            lli mid = lo + (hi - lo)/2;
            lli cnt = 1,sum = 0;
            for(int i =0;i<weights.size();i++)
            {
                sum += weights[i];
                if(sum > mid)
                {
                    sum = weights[i];
                    cnt++;
                }
            }
            if(cnt > days)
            {
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};