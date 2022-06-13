class Solution
{
    public:
        int removeDuplicates(vector<int> &nums)
        {
            int i = 0, j = 1, n = nums.size(), cnt = 0;
            vector<int> v;
            v.push_back(nums[0]);
            while (j < n)
            {
                if (nums[i] == nums[j]) j++;
                else if (nums[i] != nums[j])
                {
                    cnt++,
                    i = j;
                    v.push_back(nums[i]);
                    j++;
                }
            }
            nums = v;
            return cnt + 1;
        }
};