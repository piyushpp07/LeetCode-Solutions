class Solution {
    private:
    int solve(int n, int i, int dp[])
    {   
        if(i>n)
            return 0;
        else if(i == n)
            return 1;
        else if(dp[i]!=-1)
            return dp[i];

        return dp[i]=solve(n,i+1,dp)+solve(n,i+2,dp);
    }
public:
    int dp[46]={0};
    int climbStairs(int n) {
      int dp[n];
        for(int   i=0;i<n;i++)
        {
            dp[i]=-1;
        }
        
      return solve(n,0,dp);
        
    }
    

};