class Solution {
private :
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  int n = 0;
  int m = 0;
  void dfs(vector<vector<char>>&board, int sr, int sc)
  {
    if (sr < 0 || sc < 0 || sr >= board.size() || sc >= board[0].size())
    {
      return ;
    }
    if (board[sr][sc] == 'O')
    {
      board[sr][sc] = '#';
      for (int i = 0; i < 4; i++)
      {
        int x = sr + dx[i];
        int y = sc + dy[i];
        dfs(board, x, y);
      }
    }

  }
public:
  void solve(vector<vector<char>>&board) {
    n = board.size();
    m = board[0].size();
    for (int i = 0; i < n; i++)
    {
      if (board[i][0] == 'O')
        dfs(board, i, 0);
      if (board[i][m - 1] == 'O')
        dfs(board, i, m - 1);
    }
    for (int i = 0; i < m; i++)
    {
      if (board[0][i] == 'O')
        dfs(board, 0, i);
      if (board[n - 1][i] == 'O')
        dfs(board, n - 1, i);
    }
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (board[i][j] == '#')
          board[i][j] = 'O';
        else if (board[i][j] == 'O')
          board[i][j] = 'X';  


      }
    }


  }
};