class Solution {
    private:
    int dp[1001][1001];
    int lcs(string &a,string &b ,int n,int m){
        // if(n==0||m==0)
        //     return dp[n][m]=0;
        // if(dp[n][m]!=-1)
        //     return dp[n][m];
        // else if(a[n-1]==b[m-1])
        //     return dp[n][m] = 1+lcs(a,b,n-1,m-1);
        // else return dp[n][m] = max(lcs(a,b,n-1,m),lcs(a,b,n,m-1));
        for(int i=0;i<n+1;i++)
            for(int j=0;j<m+1;j++)
                 if(i==0||j==0)
                     dp[i][j]=0;
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else 
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
public:
    int minInsertions(string s) {
        string a=s;
        memset(dp,-1,sizeof dp);
        reverse(s.begin(),s.end());
        int n=s.length();
        int m = lcs(a,s,n,n);
        return n-m;
    }
};