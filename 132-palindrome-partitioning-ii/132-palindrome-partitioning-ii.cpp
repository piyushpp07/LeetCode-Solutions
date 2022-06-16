class Solution
{
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }

    public:
        int minCut(string str)
        {
            int n = str.size();
            vector<int> dp(2001, 0);
            dp[n - 1] = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                string temp = "";
                int minc = INT_MAX;
                for (int j = i; j < str.size(); j++)
                {
                    temp += str[j];
                    if (isPalindrome(str, i, j))
                    {
                        int cost = 1 + dp[j + 1];
                        minc = min(minc, cost);
                    }
                }
                dp[i] = minc;
            }
            return dp[0] - 1;
        }
};