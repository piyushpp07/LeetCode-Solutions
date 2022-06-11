class Solution
{
    public:
        int minOperations(vector<int> &nums, int x)
        {
            int n = nums.size();
            int l = 0, r = 0;
            int maxlen = -1, tar = 0;
            for (auto i: nums)
                tar += i;
            tar = tar - x;
            int till = nums[0];
            while (l < n && r < n)
            {
                if (till < tar)
                {
                    r++;
                    if (r == n) break;
                    till = till + nums[r];
                }
                if (till > tar)
                {
                    till = till - nums[l];
                    l++;
                }
                if (till == tar)
                {
                    int len = r - l + 1;
                    maxlen = max(len, maxlen);
                    r++;
                    if (r == n) break;
                    till = till + nums[r];
                }
            }

            return maxlen == -1 ? -1 : n - maxlen;
        }
};