class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            int ans = 0;
            for (int i = 0; i < s.size(); i++)
            {
                int minans = 0;
                map<char, int> mp;
                for (int j = i; j < s.size(); j++)
                {
                    if (mp.find(s[j]) != mp.end())
                        break;
                    minans++, mp[s[j]]++;
                }
                ans = ans > minans ? ans : minans;
            }
            return ans;
        }
};