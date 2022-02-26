class Solution {
public:
    int solve(vector<int>&prices,int i,int own,int tno, vector<vector<vector<int>>> &dp)
    {       if(tno==0||i==prices.size())
            return 0;
     
            if(dp[i][own][tno]!=-1)
            return dp[i][own][tno];
 
            if(own){
            int op1 = prices[i]+solve(prices,i+1,!own,tno-1,dp);
            int op2 = solve(prices,i+1,own,tno,dp);
            return dp[i][own][tno] = max(op1,op2);
            }
            else{
            int op1 = -prices[i]+solve(prices,i+1,!own,tno,dp);
            int op2 = solve(prices,i+1,own,tno,dp);
            return dp[i][own][tno] = max(op1,op2);
        }
            
  

    }
   public:
    
    int maxProfit(int k ,vector<int>& prices) {
      int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(prices,0,0,k,dp);
    }
};