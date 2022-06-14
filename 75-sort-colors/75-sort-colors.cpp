class Solution
{
    public:
        void sortColors(vector<int> &nums)
        {
            int zero = 0;
            int one = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == 0)
                    zero++;
                if (nums[i] == 1)
                    one++;
            }
            int lptr = 0;
            while (lptr < zero)
            {
                nums[lptr++] = 0;
            }
            one = zero + one;
            while (lptr < one)
            {
                nums[lptr++] = 1;
            }
            while (lptr < nums.size())
            {
                nums[lptr++] = 2;
            }
        }
};