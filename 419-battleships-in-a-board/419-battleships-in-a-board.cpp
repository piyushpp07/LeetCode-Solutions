class Solution
{
    private:
        int dx[2] = { 1,
            0
        };
    int dy[2] = { 0,
        1
    };
    void dfs(vector<vector < char>> &board, int sr, int sc, vector< vector< int>> &visited)
    {
        if (sr < 0 || sc < 0 || sr >= board.size() || sc >= board[0].size())
        {
            return;
        }
        visited[sr][sc] = 1;
        for (int i = 0; i < 2; i++)
        {
            int x = dx[i] + sr;
            int y = dy[i] + sc;

            if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size() && !visited[x][y] && board[x][y] == 'X')
            {
                cout << x << "<->" << y << "\n";
                dfs(board, x, y, visited);
            }
        }
    }
    public:
        int countBattleships(vector<vector < char>> &board)
        {
            int n = board.size();
            int m = board[0].size();
            int cc = 0;
            vector<vector < int>> visited(n, vector<int> (m, 0));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (board[i][j] == 'X' && !visited[i][j])
                    {
                        dfs(board, i, j, visited);
                        cc++;
                    }
                }
            }
            return cc;
        }
};