class Solution {
// private : 
//      int helper(int sr, int sc , int m , int n , vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp )
//      {   
//         if(sr>m-1||sc>n-1)
//         return 0;
//         if(obstacleGrid[sr][sc]==1)
//             return dp[sr][sc]=0;
//         if(sr==m-1||sc==n-1)
//             return dp[sr][sc]=1;
//         if(dp[sr][sc]!=-1)
//             return dp[sr][sc]=0;
//         if(sr==m-1)
//             return dp[sr][sc]=helper(sr,sc+1,m,n,obstacleGrid,dp);
//         if(sc==n-1)
//             return dp[sr][sc]=helper(sr+1,sc,m,n,obstacleGrid,dp);
//         int ans = helper(sr+1 , sc ,m ,n , obstacleGrid , dp )+helper(sr , sc+1 , m , n , obstacleGrid , dp );
//         dp[sr][sc]=ans;
//         return ans;
//      }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {   if(obstacleGrid[i][0]!=1)
            dp[i][0]=1;
            else break;
        }
        for(int i=0;i<n;i++)
        {   if(obstacleGrid[0][i]!=1)
            dp[0][i]=1;
            else 
                break;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j]!=1)   
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};