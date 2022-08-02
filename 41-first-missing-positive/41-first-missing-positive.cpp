class Solution
{
    public:
        bool find(vector<int> &nums, long long int number)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == number)
                    return true;
            }
            return false;
        }
    int firstMissingPositive(vector<int> &nums)
    {
        int x = 1;
        sort(nums.begin(),nums.end());
        while (1)
        {
            if (!binary_search(nums.begin(), nums.end(), x))
                return x;
            else
                x++;
        }
        return 1e9;
    }
};