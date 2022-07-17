class Solution
{
    private:
        int dx[8] = { -1,
            0,
            1,
            0,
            1,
            1,
            -1,
            -1
        };
    int dy[8] = { 0,
        -1,
        0,
        1,
        1,
        -1,
        1,
        -1
    };
    public:
        int shortestPathBinaryMatrix(vector<vector < int>> &grid)
        {
            int n = grid.size();
            if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
                return -1;
            else
            {
                queue<pair<int, int>> q;
                q.push({ 0,
                    0 });
                grid[0][0] = 1;
                while (!q.empty())
                {
                    auto t = q.front();
                    q.pop();
                    int a = t.first;
                    int b = t.second;
                    for (int i = 0; i < 8; i++)
                    {
                        int x = a + dx[i];
                        int y = b + dy[i];
                        if (x < n && y < n && x >= 0 && y >= 0 && grid[x][y] == 0)
                        {

                            q.push({ x,
                                y });
                            grid[x][y] = grid[a][b] + 1;
                        }
                    }
                }

                return grid[n - 1][n - 1] == 0 ? -1 : grid[n - 1][n - 1];
            }
        }
};
