class Solution
{
    public:
        int dp[21][31];
    bool f(string &s, string &p, int i, int j)
    {
        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
        {
            while (j>=0)
            {
                if (p[j] == '*')
                   j -= 2;
                else
                return false;
            }
            return true;
        }
        else if (i >= 0 && j < 0)
            return false;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == p[j] || p[j] == '.')
            return dp[i][j] = f(s, p, i - 1, j - 1);
        if (p[j] == '*')
        {
            if (p[j - 1] != s[i] && p[j - 1] != '.')
                return dp[i][j] = f(s, p, i, j-2);
            else
                return dp[i][j] = f(s, p, i, j-2) || f(s, p, i-1, j);
        }
        return false;
    }
    bool isMatch(string s, string p)
    {
        memset(dp, -1, sizeof dp);
        int a = s.size(), b = p.size();
        return f(s, p, a - 1, b - 1);
    }
};