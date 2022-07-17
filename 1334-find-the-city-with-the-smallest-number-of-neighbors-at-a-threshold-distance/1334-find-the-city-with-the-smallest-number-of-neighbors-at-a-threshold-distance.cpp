class Solution
{
    public:
        int findTheCity(int n, vector<vector < int>> &edges, int th)
        {
            int dp[n][n];

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j)
                        dp[i][j] = 0;
                    else dp[i][j] = INT_MAX;
                }
            }
            for (int i = 0; i < edges.size(); i++)
            {
                int u = edges[i][0];
                int v = edges[i][1];
                int wt = edges[i][2];
                dp[u][v] = wt;
                dp[v][u] = wt;
            }

            for (int k = 0; k < n; k++)
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (dp[i][k] != INT_MAX and dp[k][j] != INT_MAX)
                        {
                            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                        }
                    }
                }
            }
            int ans = 0, prevMin = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                int cnt = 0;
                for (int j = 0; j < n; j++)
                {
                    if (i != j && dp[i][j] <= th)
                        cnt++;
                }
                if (cnt <= prevMin)
                    ans = i, prevMin = min(cnt, prevMin);
            }
            return ans;
        }
};