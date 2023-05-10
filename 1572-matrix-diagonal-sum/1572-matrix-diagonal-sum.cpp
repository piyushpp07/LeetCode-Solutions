class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int total = 0;
        for(int i = 0;i<n;i++)
        {
            total += mat[i][i];
        }
        int i = 0;
        for(int j = n-1;j>=0;j--)
        {
            total+= mat[i++][j];
        }
        if(n&1)
            total-= mat[n/2][n/2];
        return total;
    }
};