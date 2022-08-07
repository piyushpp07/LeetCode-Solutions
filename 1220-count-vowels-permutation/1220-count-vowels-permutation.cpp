long mod = 1e9 + 7;
class Solution
{
    public:
        vector<int> adj[5];
    int dp[100001][5];
    Solution()
    {
        adj[0].push_back(1);
        adj[1].push_back(0);
        adj[1].push_back(2);
        adj[3].push_back(2);
        adj[3].push_back(4);
        adj[4].push_back(0);
    }
    int solve(int i, int n, int prev)
    {
        if (i == n)
            return 1;
        if (dp[i][prev] != -1)
            return dp[i][prev];
        else
        {
            int ans = 0;
            if (prev == 2)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (j == 2)
                        continue;
                    else
                    {
                        ans = (ans % mod + solve(i + 1, n, j) % mod) % mod;
                    }
                }
            }
            else
            {
                vector<int> a = adj[prev];
                for (int j = 0; j < a.size(); j++)
                {
                    ans = (ans % mod + solve(i + 1, n, a[j]) % mod) % mod;
                }
            }
            return dp[i][prev] = ans % mod;
        }
    }
    int countVowelPermutation(int n)
    {
        long ans = 0;
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < 5; i++)
        {
            ans = (ans % mod + solve(1, n, i) % mod) % mod;
        }
        return ans;
    }
};