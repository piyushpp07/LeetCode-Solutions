class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int [][]dp = new int[text1.length()][text2.length()];
        for(int i = 0;i<text1.length();i++)
        {
            for(int j= 0 ;j<text2.length();j++)
            {
                dp[i][j]=-1;
            }
        }
        return solve(text1,text2,0,0,dp);
        
    }
    public int solve(String X,String Y,int i ,int j,int [][]dp)
    {
        if( i == X.length() || j == Y.length())
        {
            return 0;
        }
        else if(dp[i][j]!=-1)
            return dp[i][j];
        else if(X.charAt(i)==Y.charAt(j))
            return dp[i][j] = 1+solve(X,Y,i+1,j+1,dp);
        else{
            return dp[i][j] = Math.max(solve(X,Y,i+1,j,dp),solve(X,Y,i,j+1,dp));
        }
    }
}