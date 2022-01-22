class Solution {
    Boolean []dp=new Boolean[100001];
    public boolean winnerSquareGame(int n) {
       if(dp[n]!=null)
           return dp[n];
        Boolean aliceWins = false;
        for(int move = 1; n-move*move>=0;move++)
        {
          if(n-move*move==0)
          {
              aliceWins=true;
          }
          else {
              aliceWins = aliceWins||!winnerSquareGame(n-move*move);
          }
        }
        return dp[n]=aliceWins;
    
    }
}