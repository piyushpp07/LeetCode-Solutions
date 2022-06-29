class Solution
{
    private:
        int dp[2001][2001];
    bool solve(int i, int p, vector<int> &arr, int n)
    {
        if (i == n - 1) return true;
        if (i >= n)
            return false;
        if (dp[i][p] != -1) return dp[i][p];
        bool flag = false;
        for (int k = i + 1; k < n; k++)
        {
            int diff = arr[k] - arr[i];
            if (p - 1 > 0)
            {
                if (diff == p - 1)
                {
                    int idx = p - 1;
                    flag = flag || solve(k, p - 1, arr, n);
                }
            }
            if (p == diff)
            {
                flag = flag || solve(k, p, arr, n);
            }
            if (p + 1 == diff)
            {
                flag = flag || solve(k, p + 1, arr, n);
            }
        }
        return dp[i][p] = flag;
    }

    public:
        bool canCross(vector<int> &stones)
        {
            int n = stones.size();
            memset(dp, -1, sizeof dp);
            int diff = stones[1] - stones[0];
            if (diff != 1)
                return false;
            else
                return solve(1, 1, stones, n);
        }
};