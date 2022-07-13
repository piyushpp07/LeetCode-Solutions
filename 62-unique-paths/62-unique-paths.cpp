class Solution
{
    public:
        int dp[102][102];
    int solve(int a, int b, int m, int n)
    {
        if (a == m && b == n)
            return 1;
        if (a > m || b > n)
            return 0;
        if (dp[a][b] != -1)
            return dp[a][b];
        else
            return dp[a][b] = solve(a + 1, b, m, n) + solve(a, b + 1, m, n);
    }
    int uniquePaths(int m, int n)
    {
        memset(dp, -1, sizeof dp);
        return solve(1, 1, m, n);
    }
};