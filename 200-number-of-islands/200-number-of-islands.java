class Solution {

    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    public void bfs(int i,int j,int maxrow,int maxcol,char [][]grid,int [][]vis)
    {
        if(i<0||i>=maxrow||j<0||j>=maxcol||grid[i][j]=='0'||vis[i][j]==1)
        {
            return ;
        }
        vis[i][j]=1;
        for(int k=0;k<4;k++)
        {
         int x=dx[k]+i;
         int y=dy[k]+j;
         bfs(x,y,maxrow,maxcol,grid,vis);
        }
    }
    public int numIslands(char[][] grid) {
        int maxrow = grid.length;
        int maxcol = grid[0].length;
        int [][]vis=new int[grid.length][grid[0].length];
        int island = 0;
        for(int i=0;i<maxrow;i++)
        {
            for(int j=0;j<maxcol;j++)
            {
                if(vis[i][j]==0&&grid[i][j]=='1')
                {
                    bfs(i,j,maxrow,maxcol,grid,vis);
                    island++;
                }
            }
        }
        return island;
    }
}