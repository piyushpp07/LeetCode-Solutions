class Solution
{
    int dp[501][501];
    int solve(string word1, string word2, int i, int j, int n, int m)
    {
        if (i == n || j == m)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        else if (word1[i] == word2[j])
            return dp[i][j] = 1 + solve(word1, word2, i + 1, j + 1, n, m);
        else
        {
            int a = solve(word1, word2, i + 1, j, n, m);
            int b = solve(word1, word2, i, j + 1, n, m);
            return dp[i][j] = max(a, b);
        }
    }

    public:
        int minDistance(string word1, string word2)
        {
            int n = word1.size(), m = word2.size();

            int t = max(n, m);
            memset(dp, -1, sizeof dp);
            int cal = solve(word1, word2, 0, 0, n, m);
            return (m+n- 2*cal);
        }
};