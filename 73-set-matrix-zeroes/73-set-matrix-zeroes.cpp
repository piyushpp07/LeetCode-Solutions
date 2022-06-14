class Solution
{   private:
     void set(vector<vector<int>>&matrix,int r,int c)
     {
             for(int i = 0;i<matrix.size();i++)
             {
                     matrix[i][c] = 0;
             }
             for(int i = 0;i<matrix[0].size();i++)
             {
                     matrix[r][i] = 0;
             }
     }
    public:
        void setZeroes(vector<vector < int>> &matrix)
        {
            vector<pair<int, int>> v;
            int n = matrix.size();
            int m = matrix[0].size();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (matrix[i][j] == 0)
                        v.push_back({ i,
                            j });
                }
            }
            for(auto i:v)
            {
                    int inr = i.first;
                    int inc = i.second;
                    set(matrix,inr,inc);    
            }
        }
};