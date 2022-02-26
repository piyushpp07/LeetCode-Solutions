class Solution {
public :
    int solve(vector<int>&prices,int i,int own,vector<vector<int>>&dp)
    {
        if(i==prices.size())
            return 0;
        if(dp[i][own]!=-1)
            return dp[i][own];
        if(own){
            int op1 = prices[i]+solve(prices,i+1,!own,dp);
            int op2 = solve(prices,i+1,own,dp);
            return dp[i][own] = max(op1,op2);
        }
        else{
            int op1 = -prices[i]+solve(prices,i+1,!own,dp);
            int op2 = solve(prices,i+1,own,dp);
            return dp[i][own] = max(op1,op2);
        }
    }
public:
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(prices,0,0,dp);
    }
};