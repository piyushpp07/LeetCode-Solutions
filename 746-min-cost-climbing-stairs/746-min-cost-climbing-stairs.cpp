class Solution
{
    private:
        int solve(int idx, vector<int> &cost, vector<int> &dp)
        {
            if (idx >= cost.size())
                return 0;
            if (dp[idx] != -1)
                return dp[idx];
            else
                return dp[idx] = cost[idx] + min(solve(idx + 1, cost, dp), solve(idx + 2, cost, dp));
        }
    public:
        int minCostClimbingStairs(vector<int> &cost)
        {
            vector<int> dp(cost.size(), -1);
            solve(0, cost, dp);
            return min(dp[0], dp[1]);
        }
};