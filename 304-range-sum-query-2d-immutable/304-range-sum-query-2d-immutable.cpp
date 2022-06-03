class NumMatrix
{
    private:
        int v[201][201];
    int rows = 0, cols = 0;
    public:
        NumMatrix(vector<vector < int>> &matrix)
        {   memset(v,0,sizeof v);
            int n = matrix.size();
            int m = matrix[0].size();
            rows = n;
            cols = m;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    v[i + 1][j + 1] = v[i][j + 1] + v[i + 1][j] + matrix[i][j] - v[i][j];
                }
            }
        }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        if (row1 < rows && col1 < cols && row2 < rows && col2 < cols && row1 >= 0 && col1 >= 0 && row2 >= 0 && col2 >= 0)         {
                return v[row2+1][col2+1]+v[row1][col1]-v[row1][col2+1]-v[row2+1][col1];
        }
        else return 0;
    }
};

/**
 *Your NumMatrix object will be instantiated and called as such:
 *NumMatrix* obj = new NumMatrix(matrix);
 *int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */