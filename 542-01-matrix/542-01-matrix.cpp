class Solution
{
    private:
        int X[4] = { 0,
            1,
            0,
            -1
        };
    int Y[4] = { -1,
        0,
        1,
        0
    };
    public:
        vector<vector < int>> updateMatrix(vector<vector < int>> &matrix)
        {
           	//BFS Shortest Path
            int n = matrix.size();
            int m = matrix[0].size();
            queue<pair<int, int>> q;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (matrix[i][j] == 0)
                    {
                        q.push({ i,
                            j });
                 
                    }
                    else
                        matrix[i][j] = INT_MAX;
                }
            }
            while (!q.empty())
            {
                auto i = q.front();
                int a = i.first;
                int b = i.second;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int x1 = a + X[i];
                    int y1 = b + Y[i];
                    if (x1 >= 0 && y1 >= 0 && x1 < n && y1 < m && matrix[x1][y1] != 0&&matrix[x1][y1]>matrix[a][b]+1 )
                    {
                        matrix[x1][y1] = matrix[a][b] + 1;
                        q.push({ x1,
                            y1 });
                    }
                }
            }

            return matrix;
        }
};