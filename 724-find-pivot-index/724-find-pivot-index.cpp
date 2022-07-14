class Solution
{
    public:
        int pivotIndex(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> pre(n, 0);
            pre[0] = nums[0];
            for (int i = 1; i < nums.size(); i++)
                pre[i] = pre[i - 1] + nums[i];
            for (int i = 0; i < nums.size(); i++)
                if (pre[i] - nums[i] == pre[n-1] - pre[i])
                    return i ;

            return -1;
        }
};