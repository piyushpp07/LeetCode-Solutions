class Solution {
private:
    int bts(vector<int>&prices,int fee,int i ,int own,vector<vector<int>>&dp)
    {
        if(i == prices.size())
            return 0;
        if(dp[i][own]!=-1)
            return dp[i][own];
        if(own)
        {
            int op1 = prices[i]+bts(prices,fee,i+1,!own,dp);
            int op2 = bts(prices,fee,i+1,own,dp);
            return dp[i][own] = max(op1,op2);
        }
        else{
            int op1 = -(prices[i]+fee)+bts(prices,fee,i+1,!own,dp);
            int op2 = bts(prices,fee,i+1,own,dp);
            return  dp[i][own] = max(op1,op2);
        }
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
         vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
         return bts(prices,fee,0,0,dp);
    }
};