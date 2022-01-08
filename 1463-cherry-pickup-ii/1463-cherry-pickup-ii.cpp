class Solution {
private:

    int dp[71][71][71];
    int dy[3]={0,-1,1};
    bool checker(int i , int c1, int c2 , int m ,int n)
    {
        if(i==m || c1 < 0 || c2 < 0 || c1 >= n || c2 >= n)
            return true;
        return false;
    }

    int helper(vector<vector<int>>& grid, int i, int c1, int c2) {
        int m = grid.size();
        int n = grid[0].size();
      
        if (checker(i , c1 ,c2 ,m ,n)) return 0;
        if (dp[i][c1][c2] != -1) return dp[i][c1][c2];
        
        int maxAns = 0;
        
        for (int k=0; k<3; k++) {
            for (int r=0; r<3; r++) {
                maxAns = max(maxAns, helper(grid, i + 1, c1 + dy[k], c2 + dy[r]));
            }
        }
        
        maxAns += (c1 == c2) ? grid[i][c1] : grid[i][c1] + grid[i][c2];
        return dp[i][c1][c2] = maxAns;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();
        memset(dp, -1, sizeof dp);
        return helper(grid, 0, 0, n-1);
    }
};