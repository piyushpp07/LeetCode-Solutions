class Solution {
    private:
    int dp[1001][1001];
    int lcs(string &a,string &b ,int n,int m){
        if(n==0||m==0)
            return dp[n][m]=0;
        if(dp[n][m]!=-1)
            return dp[n][m];
        else if(a[n-1]==b[m-1])
            return dp[n][m] = 1+lcs(a,b,n-1,m-1);
        else return dp[n][m] = max(lcs(a,b,n-1,m),lcs(a,b,n,m-1));
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