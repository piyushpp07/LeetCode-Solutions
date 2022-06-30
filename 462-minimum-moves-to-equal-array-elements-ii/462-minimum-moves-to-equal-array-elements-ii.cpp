class Solution
{
    public:
        int minMoves2(vector<int> &nums)
        {

            int n = nums.size();
            sort(nums.begin(), nums.end());
            if (n % 2 != 0)
            {
                int ans = 0;
                int mn = nums[n / 2];
                for (int i = 0; i < nums.size(); i++)
                    ans += abs(nums[i] - mn);
                return ans;
            }
            else
            {
                int ans = 0;
                int mn = nums[n / 2];
                int m = nums[(n / 2) - 1];
                int ans1 = 0;
                for (int i = 0; i < nums.size(); i++)
                {
                    ans += abs(nums[i] - mn);
                    ans1 += abs(nums[i] - m);
                }
                return min(ans1, ans);
            }
        }
};