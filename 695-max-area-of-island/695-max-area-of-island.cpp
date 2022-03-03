class Solution
{
    private:
        int maxArea = 0,dis = 0;
    int dx[4] = { 0,
        1,
        0,
        -1
    };
    int dy[4] = { 1,
        0,
        -1,
        0
    };
    void dfs(vector<vector < int>> &board, int sr, int sc, vector< vector< int>> &visited)
    {
        if (sr < 0 || sc < 0 || sr >= board.size() || sc >= board[0].size())
        {
            return;
        }
        if (dis > maxArea)
            maxArea = dis;
        visited[sr][sc] = 1;
        for (int i = 0; i < 4; i++)
        {
            int x = dx[i] + sr;
            int y = dy[i] + sc;

            if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size() && !visited[x][y] && board[x][y] == 1)
            {
                cout << dis +1 << "\n";
                dis++;
                dfs(board, x, y, visited);
                
            }
        }
    }
    public:
        int maxAreaOfIsland(vector<vector < int>> &grid)
        {
            int n = grid.size();
            int m = grid[0].size();
            vector<vector < int>> visited(n, vector<int> (m, 0));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (grid[i][j] == 1 && !visited[i][j])
                    {   dis=1;
                        dfs(grid, i, j, visited);
                    }
                }
            }
            return maxArea;
        }
};