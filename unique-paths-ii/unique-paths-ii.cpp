class Solution {
private : 
     int helper(int sr, int sc , int m , int n , vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp )
     {  
        if(obstacleGrid[sr][sc]==1)
            return dp[sr][sc]=0;
        if(sr==m-1&&sc==n-1)
            return dp[sr][sc]=1;
        if(dp[sr][sc]!=-1)
            return dp[sr][sc];
        if(sr==m-1)
            return dp[sr][sc]=helper(sr,sc+1,m,n,obstacleGrid,dp);
        if(sc==n-1)
            return dp[sr][sc]=helper(sr+1,sc,m,n,obstacleGrid,dp);
        int ans = helper(sr+1 , sc ,m ,n , obstacleGrid , dp )+helper(sr , sc+1 , m , n , obstacleGrid , dp );
        dp[sr][sc]=ans;
        return ans;
     }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        if(obstacleGrid[m-1][n-1]==1)
            return 0;
        return helper(0,0,m,n,obstacleGrid,dp);
    }
};