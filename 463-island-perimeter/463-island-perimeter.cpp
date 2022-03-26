class Solution {
private :
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int ans = 0;
    void dfs(int sr,int sc,vector<vector<int>>&vis,vector<vector<int>>&grid)
    {
        vis[sr][sc]=1;
        for(int i = 0;i<4;i++)
        {
            int x = dx[i]+sr;
            int y = dy[i]+sc;
            if(x>=grid.size()||y>=grid[0].size()||x<0||y<0||grid[x][y]==0){
              ans++;
            }
            else if(vis[x][y]==0&&grid[x][y]==1)
            dfs(x,y,vis,grid);
        }
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
       vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
       for(int i = 0;i<grid.size();i++)
       {
           for(int j = 0;j<grid[0].size();j++)
           {
               if(grid[i][j]==1)
               {
                   dfs(i,j,vis,grid);
                   return ans;
               }
           }
       }
       return 0;
    }
};