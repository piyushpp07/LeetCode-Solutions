class Solution
{
    public:
        int dp[100001][150];
    int solve(int i, string &s, int k, int prev)
    {
        if (i == s.size())
            return 0;
        if (dp[i][prev] != -1)
            return dp[i][prev];
        else
        {
            int p = 0, q = 0;
            if (prev == 0 || abs(s[i] - prev) <= k)
                p = 1 + solve(i + 1, s, k, s[i]);	// can take and and take
            q = 0 + solve(i + 1, s, k, prev);	// can take or not take but no taking
            return dp[i][prev] = max(p, q);
        }
    }
    int longestIdealString(string s, int k)
    {
        int n = s.size();
        memset(dp, -1, sizeof dp);
        return solve(0, s, k, 0);
    }
};