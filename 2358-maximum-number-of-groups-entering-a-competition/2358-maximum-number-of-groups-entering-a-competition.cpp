class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int lo = 1,hi = 1000,n = grades.size();
        while(lo<hi)
        {
            int mid = (lo+hi+1)/2;
            if(mid*(mid+1)/2<=n)
                lo = mid;
            else hi = mid-1;
        }
        return lo;
    }
};