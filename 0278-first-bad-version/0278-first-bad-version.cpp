// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#define lli long long int

class Solution {
public:
    int firstBadVersion(int n) {
        lli lo = 0,hi = n, ans = n;
        while(lo<=hi)
        {
            lli mid = (lo + hi)/2;
            if(isBadVersion(mid) == true)
                hi = mid - 1, ans = mid;
            else {
                lo = mid  +  1;
            }
        }
        return ans;
    }
};