class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<int>prev(m,0);
        for(int i = 0;i<n;i++)
        {
            vector<int>curr(m,0);
            for(int j = 0;j<m;j++)
            {
                if(i == 0 && j == 0)
                curr[j] = grid[i][j];
                else{
                    int up = grid[i][j] ,left = grid[i][j];

                    if(i>0)
                        up += prev[j];

                    else up += 1e9;
                
                    if(j>0)
                         left += curr[j-1];
                    else
                        left+=1e9;
                    curr[j] = min(up,left);

                }
            }
            prev = curr;
        }
        return prev[m-1];
    }
    
};