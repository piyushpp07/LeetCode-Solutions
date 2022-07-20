// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
    public:
        int firstBadVersion(int n)
        {
            long long int lo = 1, hi = n;
            long long int recent=-1;
            while (lo <= hi)
            {
                int mid = (lo + hi) / 2;
                if (isBadVersion(mid))
                    hi = mid - 1, recent = mid;
                else lo = mid + 1;
            }
            return recent;
        }
};