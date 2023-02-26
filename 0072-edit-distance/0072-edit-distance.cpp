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
        memset(dp, -1, sizeof dp);
        int ans = solve(n - 1, m - 1, a, b);
        return ans;
    }
};