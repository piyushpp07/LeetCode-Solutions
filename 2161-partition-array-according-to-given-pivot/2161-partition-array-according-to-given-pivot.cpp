class Solution
{
    public:
        vector<int> pivotArray(vector<int> &nums, int pivot)
        {
            vector<int> before;
            vector<int> after,mid;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] > pivot)
                {
                    after.push_back(nums[i]);
                }
                else if (nums[i] == pivot)
                    mid.push_back(nums[i]);
                else
                    before.push_back(nums[i]);
            }
            for(int i = 0;i<mid.size();i++)
            {
                    before.push_back(mid[i]);
            }
            for (int i = 0; i < after.size(); i++)
            {
                before.push_back(after[i]);
            }
            return before;
        }
};