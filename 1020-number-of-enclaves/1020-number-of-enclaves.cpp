class Solution
{
    int dx[4] = { 1,
        0,
        -1,
        0
    };
    int dy[4] = { 0,
        -1,
        0,
        1
    };
    void dfs(int r, int c, vector<vector < int>> &arr)
    {
        arr[r][c] = -1;
        for (int i = 0; i < 4; i++)
        {
            int x = dx[i] + r;
            int y = dy[i] + c;
            if (x < 0 || y < 0 || x >= arr.size() || y >= arr[0].size() || arr[x][y] == -1 || arr[x][y] == 0)
                continue;
            dfs(x, y, arr);
        }
    }
    public:
        int numEnclaves(vector<vector < int>> &arr)
        {
            int n = arr.size();
            int m = arr[0].size();
            for (int i = 0; i < n; i++)
            {
                if (arr[i][0] == 1)
                {
                    dfs(i, 0, arr);
                }
                if (arr[i][m - 1] == 1)
                {
                    dfs(i, m - 1, arr);
                }
            }
            for (int i = 0; i < m; i++)
            {
                if (arr[0][i] == 1)
                {
                    dfs(0, i, arr);
                }
                if (arr[n - 1][i] == 1)
                {
                    dfs(n - 1, i, arr);
                }
            }
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (arr[i][j] == 1)
                        cnt++;
                }
            }
            return cnt;
        }
};