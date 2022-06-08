class Solution
{
    private:
        using pii = pair<int, pair<int, int>> ;
    int dx[4] = { 0,
        1,
        0,
        -1
    };
    int dy[4] = { -1,
        0,
        1,
        0
    };
    queue<pii> q;
    public:
        int maxDistance(vector<vector < int>> &grid)
        {
            int n = grid.size();
            int m = grid[0].size();
            vector<vector < int>> vis(n, vector<int> (m, 0));
                int zc = 0;
                int oc = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (grid[i][j] == 1){
                        q.push({ 0,
                            {
                                i,
                                j
                            } });
                    vis[i][j] = 1;
                            oc++;
                    }
                        else 
                        {
                                zc++;
                                grid[i][j] = -1;
                        }
                        
                }
            }
            int maxi = -1;

            while (!q.empty())
            {
                auto ft = q.front();
                int ax = ft.second.first;
                int ay = ft.second.second;
                int wt = ft.first;
                q.pop();
                maxi = max(maxi, wt);

                for (int i = 0; i < 4; i++)
                {
                    int x = ax + dx[i];
                    int y = ay + dy[i];
                    if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == -1 && !vis[x][y])
                    {
                        q.push({ wt + 1,
                            {
                                x,
                                y
                            } });
                        vis[x][y] = 1;
                            grid[x][y] = wt+1;
                    }
                }
            }
            if(oc == n*m || zc == n*m) return -1;
            return maxi;
        }
};