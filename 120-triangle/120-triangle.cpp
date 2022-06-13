class Solution
{
    int dp[201][201];
    int solve(vector<vector < int>> &triangle, int i, int j, vector< vector< int>> &dp)
    {
        if (i == triangle.size() - 1)
            return triangle[i][j];
        if (dp[i][j] != INT_MAX)
            return dp[i][j];
        int min_Ans = INT_MAX;
        min_Ans = min(min_Ans, triangle[i][j] + solve(triangle, i + 1, j, dp));
        min_Ans = min(min_Ans, triangle[i][j] + solve(triangle, i + 1, j + 1, dp));
        return dp[i][j] = min_Ans;
    }
    public:
        int minimumTotal(vector<vector < int>> &q)
        {
            vector<vector < int>> dp(q.size(), vector<int> (q[q.size() - 1].size(), INT_MAX));
                return solve(q, 0, 0, dp);
            }
        };