class Solution
{
    public:
        int longestPalindrome(string s)
        {
            int freq[128] = { 0 };
            for (auto i: s)
                freq[i]++;
            int oddgrp = 0;
            for (int i = 0; i < 128; i++)
            {
                if (freq[i] % 2 != 0)
                    oddgrp++;
            }
            return s.size() - oddgrp + (oddgrp > 0);
        }
};