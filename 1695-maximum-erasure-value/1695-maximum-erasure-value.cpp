class Solution
{
    public:
        int maximumUniqueSubarray(vector<int> &nums)
        {
            unordered_set<int> seen;
            int curr_sum = 0, max_sum = 0, l = 0;
            for (auto i: nums)
            {
                while (seen.find(i) != seen.end())
                {
                    curr_sum -= nums[l];
                    seen.erase(nums[l]);
                    l += 1;
                }
                curr_sum += i;
                seen.insert(i);
                max_sum = max(max_sum, curr_sum);
            }
            return max_sum;
        }
};