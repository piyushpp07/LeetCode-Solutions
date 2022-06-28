class Solution
{
    public:
        int minDeletion(vector<int> &nums)
        {
            if (nums.size() == 1)
                return 1;
            int cnt = 0, i = 0;
            while (i < nums.size())
            {
                if (i  < nums.size()-1 && nums[i] == nums[i + 1])
                {
                    i++;
                    cnt++;
                }
                else i+=2;
            }
            if ((nums.size() -cnt)% 2 != 0)
                return cnt + 1;
            return cnt;
        }
};