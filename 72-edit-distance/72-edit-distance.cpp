class Solution
{
    int dp[1001][1001];
    public:
        int solve(int i, int j, string &a, string &b)
        {
            if (i < 0)
                return j + 1;
            else if (j < 0)
                return i + 1;
            if (dp[i][j] != -1)
                return dp[i][j];
            else
            {
                if (a[i] == b[j])
                    return dp[i][j] = solve(i - 1, j - 1, a, b);
                else
                    return dp[i][j] = 1 + min({ solve(i - 1, j, a, b),
                        solve(i, j - 1, a, b),
                        solve(i - 1, j - 1, a, b) });
            }
        }
    int minDistance(string a, string b)
    {
        int n = a.size(), m = b.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        for (int i = 0; i <= m; i++)
            prev[i] = i;
        for (int i = 1; i <= n; i++)
        {
            curr[0] = i;
            for (int j = 1; j <= m; j++)
            {
                if (a[i - 1] == b[j - 1])
                    curr[j] = prev[j - 1];
                else
                    curr[j] = 1 + min(prev[j - 1], min(prev[j], curr[j - 1]));
            }
            prev = curr;
        }
        return prev[m];
    }
};