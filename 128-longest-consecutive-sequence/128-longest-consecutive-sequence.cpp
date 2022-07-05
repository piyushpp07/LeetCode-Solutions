class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            if (nums.size() == 1)
                return 1;
            if (nums.size() == 0)
                return 0;
            sort(nums.begin(), nums.end());
            int maxl = 1, currlen = 1;
            for (int i = 0; i < nums.size(); i++)
            {
                if (i + 1 < nums.size() && nums[i + 1] == nums[i] + 1)
                {
                    currlen++;
                    maxl = max(currlen, maxl);
                }
                else if (i + 1 < nums.size() && nums[i + 1] == nums[i] ){
                        continue;
                }
                else
                {
                    currlen = 1;
                }
            }
            return maxl;
        }
};