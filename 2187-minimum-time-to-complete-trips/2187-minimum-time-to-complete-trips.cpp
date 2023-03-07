using lli = unsigned long long int;
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(),time.end());
        lli lo = 1,hi = 1e16,ans = 0;

        while(lo<=hi)
        {
            lli mid = lo + (hi - lo)/2;
            lli ct  = 0;
            for(int i = 0 ; i < time.size() ; i++)
            {
                ct += ( mid/time[i] );
            }
            if(ct >= totalTrips)
                hi = mid - 1, ans = mid;
            else lo = mid + 1;
        }
        
        return ans;
    }
};