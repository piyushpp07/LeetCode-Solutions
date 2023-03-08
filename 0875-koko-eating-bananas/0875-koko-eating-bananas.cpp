using lli = long long int;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        lli lo = 1,hi = 0,n= piles.size(),ans = INT_MAX;
        for(int i = 0;i<n;i++)
            hi += piles[i];
        sort(piles.begin(),piles.end());
        while(lo<=hi)
        {
            lli mid = lo + (hi - lo)/2;
            lli cnth = 0;
            for(int i = 0;i<piles.size();i++)
            {
                cnth += (piles[i]/mid);
                if(piles[i]%mid)
                    cnth++;
            }
            if(cnth <= h)
            {
                hi = mid - 1,ans = mid;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};