class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &nums)
        {
            sort(nums.begin(), nums.end());
            vector<vector < int>> ans;
            for (int i = 0; i < nums.size(); i++)
            {
                if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
                {
                    vector<int> v;
                    int lo = i + 1, hi = nums.size() - 1, sum = 0 - nums[i];
                    while (lo < hi)
                    {
                        if (nums[lo] + nums[hi] == sum)
                        {

                            ans.push_back({ nums[i],
                                nums[lo],
                                nums[hi] });
                            int lw = nums[lo];
                            int hw = nums[hi];
                            while (lo < hi && nums[lo] == lw)
                                lo++;
                            while (lo < hi && nums[hi] == hw)
                                hi--;
                        }
                        else if (nums[lo] + nums[hi] > sum)
                            hi--;
                        else lo++;
                    }
                }
            }
            return ans;
        }
};