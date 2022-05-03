class Solution {
private:
       int vis[100][100];
       int maxg = 0;
       int dx[4]={1,0,-1,0};
       int dy[4]={0,-1,0,1};
int isValid(int i,int j,int n, int m,vector<vector<int>>&grid)
{
        if(i>=0&&j>=0&&i<n&&j<m&&vis[i][j]==0&&grid[i][j]!=0)
                return true;
        return false;
}
int solve(vector<vector<int>>&grid,int i , int  j,int m,int n)
{
        vis[i][j]=1;
        int t = 0;
        for(int d = 0;d<4;d++)
        {
                int x = dx[d]+i;
                int y = dy[d]+j;
                if(isValid(x,y,m,n,grid))
                        t = max(t,grid[x][y]+solve(grid,x,y,m,n)); 
        }
        vis[i][j]=0;
        return  t;
}
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        memset(vis,0,sizeof vis);
        for(int i = 0;i<m;i++)
        {
                for(int j = 0;j<n;j++)
                {       memset(vis,0,sizeof vis);
                        if(grid[i][j]!=0)
                        {
                               int g =  grid[i][j]+solve(grid,i,j,m,n);
                               maxg= max(g,maxg);
                        }
                }
        }
            return maxg;
    }
};