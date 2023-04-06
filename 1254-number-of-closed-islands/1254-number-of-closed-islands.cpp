class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};  
    
    bool isValid(vector<vector<int>>&grid,vector<vector<int>>&vis,int x,int y)
    {
        if(x >= 0 && y>= 0 && x<grid.size() && y <grid[0].size() && vis[x][y] == 0 && grid[x][y] == 0 )
            return true;
        return false;
    }

    void dfs(vector<vector<int>>&vis,vector<vector<int>>&grid,int x,int y)
    {
        vis[x][y] = 1;
        for(int i =0;i<4;i++)
        {
            int _x = dx[i] + x;
            int _y = dy[i] + y;
            if(isValid(grid,vis,_x,_y))
            {
                dfs(vis,grid,_x,_y);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i =0;i<n;i++)
        {
            if(grid[i][0] == 0)
            dfs(vis,grid,i,0);
            if(grid[i][m-1] == 0)
            dfs(vis,grid,i,m-1);
        }
        for(int j= 0;j<m;j++)
        {
            if(grid[0][j] == 0)
            dfs(vis,grid,0,j);
            if(grid[n-1][j] == 0)
            dfs(vis,grid,n-1,j);
        }
        int cnt =0;
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(vis[i][j] == 0 && grid[i][j] == 0)
                {
                    dfs(vis,grid,i,j);
                    cnt++;
                }
            }
        }
        return cnt;  
        
    }
};