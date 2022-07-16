class Solution
{
    int dx[4] = { -1,
        0,
        1,
        0
    };
    int dy[4] = { 0,
        1,
        0,
        -1
    };
    long mod = 1e9 + 7;
    public:
        bool valid(int sr, int sc, int m, int n)
        {
            if (sr >= 0 && sc >= 0 && sr < m && sc < n)
                return true;
            return false;
        }
    int dp[51][51][51];
    long long int solve(int sr, int sc, int m, int n, int maxMove)
    {
        if (maxMove == 0)
            return 0;
        if (dp[sr][sc][maxMove] != -1)
            return dp[sr][sc][maxMove];
        long long int ans = 0;
        for (int i = 0; i < 4; i++)
        {
            int x = dx[i] + sr;
            int y = dy[i] + sc;
            if (!valid(x, y, m, n))
                ans = (ans + 1) % mod;
            else
                ans = (ans + solve(x, y, m, n, maxMove - 1)) % mod;
        }
        return dp[sr][sc][maxMove] = (ans % mod);
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        memset(dp, -1, sizeof dp);
        return solve(startRow, startColumn, m, n, maxMove);
    }
};