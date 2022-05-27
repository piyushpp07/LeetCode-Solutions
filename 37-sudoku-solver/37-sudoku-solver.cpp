class Solution
{
    private:
        void display(vector<vector < int>> &board, vector< vector< char>> &grid)
        {
            int n = board.size();
            int m = board[0].size();
            cout << "[";
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (grid[i][j] == '.')
                        grid[i][j] = board[i][j]+'0';
                }
            }
        }
    bool isValid(int x, int y, vector<vector < int>> &board, int val)
    {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            if (board[x][i] == val)
                return false;
            else if (board[i][y] == val)
                return false;
        }
        int sx = x / 3 * 3;
        int sy = y / 3 * 3;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[sx + i][sy + j] == val)
                    return false;
            }
        }
        return true;
    }
    void solve(int r, int c, int n, int m, vector<vector < int>> &board, vector< vector< char>> &grid)
    {
        if (r == n)
        {
            display(board, grid);
            return;
        }
        int nr = 0;
        int nc = 0;
        if (c == m - 1)
        {
            nr = r + 1;
            nc = 0;
        }
        else
        {
            nr = r;
            nc = c + 1;
        }
        if (board[r][c] != 0)
        {
            solve(nr, nc, n, m, board,grid);
        }
        else
        {
            for (int i = 0; i < 10; i++)
            {
                if (isValid(r, c, board, i))
                {
                    board[r][c] = i;
                    solve(nr, nc, n, m, board, grid);
                    board[r][c] = 0;
                }
            }
        }
    }

    public:
        void solveSudoku(vector<vector < char>> &board)
        {
            int n = board.size();
            int m = board[0].size();
            vector<vector < int>> sudoku(n, vector<int> (m, 0));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (board[i][j] == '.')
                        continue;
                    else
                    {
                        sudoku[i][j] = board[i][j] - '0';
                    }
                }
            }
            solve(0, 0, n, m, sudoku, board);
        }
};