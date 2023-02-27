        
        
class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
  
    
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        pq.push({grid[0][0],0,0});
        while(pq.size())
        {
            int time = pq.top()[0],x = pq.top()[1],y = pq.top()[2];
            pq.pop();
            if(x == n-1 && y == m-1)
                return time;
            if(vis[x][y])
                continue;
            vis[x][y] = 1;
            for(int i = 0;i<4;i++)
            {
                int d_x = dx[i] + x, d_y = dy[i]+y;
                if(d_x < 0 || d_y < 0 || d_x >= n || d_y >=m || vis[d_x][d_y])
                    continue;
                int waittime = (grid[d_x][d_y] - time)%2==0?1:0;
                pq.push({max(time+1,grid[d_x][d_y]+waittime),d_x,d_y});
            }
            
        }
        return -1;
        
        
    }
};
