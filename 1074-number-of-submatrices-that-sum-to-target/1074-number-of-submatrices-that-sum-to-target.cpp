class Solution
{
    public:
        int numSubmatrixSumTarget(vector<vector < int>> &matrix, int target)
        {
            int n = matrix.size();
            int m = matrix[0].size();
            for (int i = 0; i < n; i++)
            {
                for (int j = 1; j < m; j++)
                {
                    matrix[i][j] += matrix[i][j - 1];
                }
            }
            int cnt = 0;
            for (int c1 = 0; c1 < m; c1++)
            {
                for (int c2 = c1; c2 < m; c2++)
                {
                    unordered_map<int, int> mp;
                    mp[0] = 1;
                    int currsum = 0;
                
                    for (int row = 0; row < n; row++)
                    {
                        currsum += matrix[row][c2] - (c1 > 0 ? matrix[row][c1 - 1] : 0);
                        cnt += (mp.find(currsum - target) != mp.end()) ? mp[currsum - target] : 0;
                        mp[currsum]++;
                    }
                }
            }
            return cnt;
        }
};