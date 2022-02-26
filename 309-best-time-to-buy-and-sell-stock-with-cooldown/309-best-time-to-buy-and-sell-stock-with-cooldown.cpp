class Solution {
private:
    int dp[5001][2][2];
    int solve(vector<int>&prices,int i,int own,int sold)
    {
        if(i==prices.size())
            return 0;
        if(dp[i][own][sold]!=-1)
            return dp[i][own][sold];
        if(sold == 1)
            return dp[i][own][sold] = solve(prices,i+1,own,!sold);
        else{
         if(own){
            int op1 = prices[i]+solve(prices,i+1,!own,1);
            int op2 = solve(prices,i+1,own,0);
            return dp[i][own][sold] = max(op1,op2);
        }
        else{
            int op1 = -prices[i]+solve(prices,i+1,!own,0);
            int op2 = solve(prices,i+1,own,0);
            return dp[i][own][sold] = max(op1,op2);
        }           
        }

    }
public:
    
    int maxProfit(vector<int>& prices) {
       memset(dp,-1,sizeof dp);
        return solve(prices,0,0,0);
    }
};