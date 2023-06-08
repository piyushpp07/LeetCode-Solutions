class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid[0].size() - 1;
        int j = 0;
        int m = grid.size();
        int i = n;
        int cnt = 0;
        while(j<m)
        {
           if( i >= 0 && grid[j][i] < 0) 
           {
               cnt++;
               i--;
           }
            else{
              j++;
              i = n;
            }

        }
        return cnt;
    }
};