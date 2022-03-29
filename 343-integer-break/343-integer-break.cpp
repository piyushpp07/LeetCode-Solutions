class Solution {
private:
	int solve(int n, vector<int>&dp)
	{	if (n == 0)
			return 0;
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;
		if (n == 4)
			return 4;
		if (n == 5)
			return 6;
		if (n == 6)
			return 9;
		if (n == 7)
			return 12;
		if (n == 8)
			return 18;
		if (n == 9)
			return 27;
		if (dp[n] != -1)
			return dp[n];
		int maxAns = 1;

		for (int i = 1; i < n; i++)
		{
			maxAns = max(maxAns, (i) * solve(n - i, dp));
		}
		return dp[n] = maxAns;
	}
public:
	int integerBreak(int n) {
		vector<int>dp(n + 1, -1);
		int ans = solve(n, dp);
		return ans;
	}
};