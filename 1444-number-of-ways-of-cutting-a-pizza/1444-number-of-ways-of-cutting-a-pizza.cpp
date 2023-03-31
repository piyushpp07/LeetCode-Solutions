int mod = 1e9+7;
class Solution {
public:
    int dfs(int n,int m,int k,int r,int c,vector<vector<vector<int>>>&dp,vector<vector<int>>&preSum)
    {
        if(preSum[r][c] == 0)
            return 0;
        if(k == 0)
            return 1;
    
        if (dp[k][r][c] != -1) return dp[k][r][c];
        int ans = 0;
        for (int nr = r + 1; nr < n; nr++) 
            if (preSum[r][c] - preSum[nr][c] > 0)
                ans = (ans + dfs(n, m, k - 1, nr, c, dp, preSum)) % 1000000007;
        for (int nc = c + 1; nc < m; nc++) 
            if (preSum[r][c] - preSum[r][nc] > 0)
                ans = (ans + dfs(n, m, k - 1, r, nc, dp, preSum)) % 1000000007;
        return dp[k][r][c] =     ans;
    }
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size(),m = pizza[0].size();
        vector<vector<vector<int>>> dp(vector(k, vector(n, vector(m, -1))));
        vector<vector<int>> pre(vector(n+1, vector(m+1, 0)));
        for(int r = n - 1;r >=0;r--)
        {
            for(int c = m - 1;c>=0;c--)
            {
                pre[r][c] = pre[r+1][c]+pre[r][c+1] - pre[r+1][c+1] + (pizza[r][c] == 'A');
            }
        }
        return dfs(n,m,k-1,0,0,dp,pre);
    }
};