#define lli long long int
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int  lo = 1,hi = 1e9,ans = 0;
        sort(candies.begin(),candies.end());
        while(lo<=hi)
        {
            int mid = (lo+hi)/2;
            lli cnt = 0;
            for(auto i : candies)
            {
                 cnt += i/mid;
            }
            if(cnt>=k)
            {
                lo = mid + 1;
                ans = mid;
            }
            else{
                 hi = mid - 1;
            }
        }
        return ans ;
    }
};