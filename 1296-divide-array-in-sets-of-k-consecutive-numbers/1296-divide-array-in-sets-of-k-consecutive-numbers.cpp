class Solution
{
    public:
        bool isPossibleDivide(vector<int> &nums, int k)
        {
            int n = nums.size();
            map<int, int> mp;
            for (int i = 0; i < n; i++)
            {
                mp[nums[i]]++;
            }
            for (auto p = mp.begin(); p != mp.end();)
            {
                if (p->second > 0)
                {
                    for (int i = 0; i < k; i++)
                    {
                        if (mp[p->first + i] > 0)
                        {
                            mp[p->first + i]--;
                        }
                        else
                            return false;
                    }
                }
                else
                    p++;
            }

            return true;
        }
};