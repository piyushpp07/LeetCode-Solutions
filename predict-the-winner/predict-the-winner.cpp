class Solution {
    private: 
    int dp[1001][1001];
    int solve(int i,int j, vector<int>&piles)
    {   
        if(i>j) return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        else
            return dp[i][j]=
        max(piles[i]+min(solve(i+2,j,piles),solve(i+1,j-1,piles)),piles[j]+min(solve(i,j-2,piles),solve(i+1,j-1,piles)));
        
    }
public:
    bool PredictTheWinner(vector<int>& piles) {
        int n = piles.size();
        int i=0,j=n-1;
        memset(dp,-1,sizeof dp);
        int sum=0;
        for(int p=0;p<=j;p++)
        {
            sum+=piles[p];
        }
        int k=solve(i,j,piles);
        cout<<k;
        return  k>=sum-k?true:false;
    }
};