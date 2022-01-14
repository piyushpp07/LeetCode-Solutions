class Solution {
private:
    int dp[1001][1001];

    int helper(int i,int n ,int l)
    {  
       if(i>n)
            return 2000;
        else if(!(n-i))
            return 0;
        else if(dp[i][l]!=-1)
            return dp[i][l];
        else{
            int copy = 2 + helper(i+i,n,i);
            int paste = 1 + helper(i+l,n,l);
            return dp[i][l] = min(copy,paste);
        }
         
    }
public:
    int minSteps(int n) {
       memset(dp,-1,sizeof dp);
       return n==1?0:1+helper(1,n,1);
    }
};