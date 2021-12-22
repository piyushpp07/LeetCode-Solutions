class Solution {
    private:
   long lcs(int i , int j ,vector<vector<int>>&matrix , int n,vector<vector<int>>&dp)
    {   if(i==n)
        return 0;
        if(i>=n||j>=n||j<0)
        return INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        else 
        {
            long p1=lcs(i+1,j+1,matrix,n,dp);
            long p2=lcs(i+1,j,matrix,n,dp);
            long p3=lcs(i+1,j-1,matrix,n,dp);
            long p4 = min(p1,min(p2,p3));
            return dp[i][j]= matrix[i][j] + p4;
    }
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long ans = INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {   long q =lcs(0,i,matrix,n,dp);
            cout<<q<<"\n";
            ans = min(ans,q);
        }
        return ans;
    }
};