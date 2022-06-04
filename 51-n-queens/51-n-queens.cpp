class Solution
{
    private:
        vector<vector < string>> a;
    bool isValid(int r, int c, int n, vector<string> &ans)
    {
        for (int i = 0; i < r; i++)
        {
            if (ans[i][c] == 'Q')
                return false;
        }
        for (int i = 0; i < c; i++)
        {
            if (ans[r][i] == 'Q')
                return false;
        }
        int a = r, b = c;
        while (a >= 0 && b >= 0)
        {
            if (ans[a][b] == 'Q')
                return false;
            a--, b--;
        }
        a = r, b = c;
        while (a >= 0 && b < n)
        {
            if (ans[a][b] == 'Q')
                return false;
            a--, b++;
        }
        return true;
    }
    void nQueens(int r, int c, int n, vector<string> &ans)
    {
        if (r == n)
        {
            a.push_back(ans);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (isValid(r, i, n, ans))
            {
                ans[r][i] = 'Q';
                nQueens(r + 1, 0, n, ans);
                ans[r][i] = '.';
            }
        }
    }
    public:
        vector<vector < string>> solveNQueens(int n)
        {
            vector<string> ans(n, string(n, '.'));
            nQueens(0, 0, n, ans);
            return a;
        }
};