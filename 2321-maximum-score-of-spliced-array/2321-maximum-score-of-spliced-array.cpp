class Solution
{
    int sum(vector<int> &a)
    {
        int ans = 0;
        for (auto i: a)
            ans += i;
        return ans;
    }

    int kadane(vector<int> &v1, vector<int> &v2)
    {
        int n = v1.size();
        int meh = 0, msf = 0;
        vector<int>z(n,0);
        for(int i = 0;i<n;i++)
        {
                z[i] = v1[i]-v2[i];
        }
        for (int i = 0; i < n; i++)
        {
            meh = meh + z[i];
            if (meh < 0)
                meh = 0;
            else
                msf = max(msf, meh);
        }
        return msf;
    }
    public:
        int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2)
        {

            int sum1 = sum(nums1);
            int sum2 = sum(nums2);
            int a1 = max(sum2, sum1 + kadane(nums2, nums1));
            int a2 = max(sum1, sum2 + kadane(nums1, nums2));
            return max(a1, a2);
        }
};