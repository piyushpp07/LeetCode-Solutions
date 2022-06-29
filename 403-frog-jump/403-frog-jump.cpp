class Solution
{
    private:
        int dp[2001][2001];
    int tr[3] = { -1,
        0,
        1
    };
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
            for (int m = 0; m < 3; m++)
            {
                int jump = tr[m] + p;
                if (jump > 0)
                {
                    if (diff == jump)
                        flag = flag || solve(k, jump, arr, n);
                }
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