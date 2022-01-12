class Solution {
int dp[201][201];
private:
    int helper(int i ,int j, int n ,int m ,vector<vector<int>>&arr )
    {
        if(i>n-1||j>m-1)
            return INT_MAX;
        
        if(i==n-1&&j==m-1)
            return dp[i][j]= arr[i][j];
    
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(i==n-1)
            return  dp[i][j] = helper(i,j+1,n,m,arr)+arr[i][j];
        
        if(j==m-1)
            return  dp[i][j] = helper(i+1,j,n,m,arr)+arr[i][j];
        
        return dp[i][j]= min(helper(i+1,j,n,m,arr),helper(i,j+1,n,m,arr))+arr[i][j];
    }
public:
    int minPathSum(vector<vector<int>>& arr) {
        int n=arr.size();
        memset(dp,-1,sizeof dp);
        int m=arr[0].size();
        return helper(0,0,n,m,arr);
    }
};