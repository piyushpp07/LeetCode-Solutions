class Solution
{
    int dx[4] = { -1,
        0,
        1,
        0
    };
    int dy[4] = { 0,
        1,
        0,
        -1
    };
    // logic try to join the connected components with the 0 wala land
    vector<vector < int>> grid;
    public:

        int dfs(int sx, int sy, int index)
        {
            int n = grid.size();
            int m = grid[0].size();
            grid[sx][sy] = index;
            int ans = 0;
            for (int i = 0; i < 4; i++)
            {
                int x = dx[i] + sx;
                int y = dy[i] + sy;
                if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1)
                {

                    ans += 1 + dfs(x, y, index);
                }
            }

            return ans;
        }
    int largestIsland(vector<vector < int>> &g)
    {
        grid = g;
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        int index = 2;
        unordered_map<int, int> area;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    int q = 1 + dfs(i, j, index);
                    area[index++] = q;
                    ans = max(ans, q);
                }
            }
        }
        for (int x = 0; x < n; ++x)
        {
            for (int y = 0; y < m; ++y)
                if (grid[x][y] == 0)
                {

                    unordered_set<int> seen = {};
                    int cur = 1;
                    for (int i = 0; i < 4; i++)
                    {
                        int sx = dx[i] + x;
                        int sy = dy[i] + y;
                        if (sx >= 0 && sy >= 0 && sx < n && sy < m && grid[sx][sy])
                        {
                            index = grid[sx][sy];
                            if (index > 1 && seen.count(index) == 0)
                            {
                                seen.insert(index);
                                cur += area[index];
                            }
                        }
                    }

                    ans = max(ans, cur);
                }
        }
        return ans;
    }
};