class Solution
{
    public:
        int characterReplacement(string s, int k)
        {
            int i = 0, j = 0, end = s.size(), ans = 0;
            vector<int> arr(26, 0);
            while (j < end && i < end)
            {
                int maxfreq = 0;
                arr[s[j] - 'A']++;
                for (int p = 0; p < 26; p++)
                    maxfreq = max(maxfreq, arr[p]);
                if ((j - i + 1) - maxfreq <= k)
                {
                    ans = max(ans, j - i + 1);
                }
                else
                {
                    arr[s[i] - 'A']--;
                    i++;
                }
                j++;
            }
            return ans;
        }
};