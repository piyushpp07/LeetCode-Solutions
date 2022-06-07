int X[] = { 0,
    1,
    0,
    -1
};
int Y[] = { -1,
    0,
    1,
    0
};
class Solution
{
    public:
        bool isvalid(int i, int j, int m, int n)
        {
            return (i >= 0 && i < m && j >= 0 && j < n);
        }

    vector<vector < int>> updateMatrix(vector<vector < int>> &matrix)
    {
       	//BFS Shortest Path
        int n = matrix.size();
        int m = matrix[0].size();
        if (m == 0)
            return {};
        queue<pair<int, int>> q;
        vector<vector < int>> result(n, vector<int> (m, INT_MAX));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    q.push({ i,
                        j });
                    result[i][j] = 0;
                }
                else
                    matrix[i][j] = -1;
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
                if (x1 >= 0 && y1 >= 0 && x1 < n && y1 < m && matrix[x1][y1] != 0 && result[x1][y1] > result[a][b] + 1)
                {
                    result[x1][y1] = result[a][b] + 1;
                    q.push({ x1,
                        y1 });
                }
            }
        }

        return result;
    }
};