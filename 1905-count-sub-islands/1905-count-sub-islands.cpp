class Solution
{
    public:
        bool ans = false;
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
    int dfs(int s_x, int s_y, vector<vector < int>> &grid1, vector< vector< int>> &grid2)
    {
        grid2[s_x][s_y] = 0;
        int res = 1;

        for (int i = 0; i < 4; i++)
        {
            int c_x = dx[i] + s_x;
            int c_y = dy[i] + s_y;
            if (c_x >= 0 && c_y >= 0 && c_x < grid1.size() && c_y < grid1[0].size() && grid2[c_x][c_y])
                res = res &dfs(c_x, c_y, grid1, grid2);
        }
        return res &grid1[s_x][s_y];
    }
    int countSubIslands(vector<vector < int>> &grid1, vector< vector< int>> &grid2)
    {
        int n = grid2.size(), m = grid2[0].size(), cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid2[i][j] && dfs(i, j, grid1, grid2))
                {

                    cnt++;
                }
                ans = true;
            }
        }
        return cnt;
    }
};