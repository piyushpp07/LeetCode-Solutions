        vector<int> dp(31, -1);
        class Solution
        {

            public:
                int fib(int n)
                {
                    if (n == 0 || n == 1) return n;
                    if (dp[n] != -1)
                        return dp[n];
                    else return dp[n] = fib(n - 1) + fib(n - 2);
                }
        };