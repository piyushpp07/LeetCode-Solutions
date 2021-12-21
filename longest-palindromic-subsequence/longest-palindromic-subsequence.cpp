class Solution {
    private:
    int dp[1001][1001];
    int lcs(string &s,string &sr , int n,int m)
    {
        if(n==0||m==0)
            return dp[n][m] = 0;
        if(dp[n][m]!=-1)
            return dp[n][m];
        else if (s[n-1]==sr[m-1])
            return dp[n][m] = 1+lcs(s,sr,n-1,m-1);
        else 
            return dp[n][m]=max(lcs(s,sr,n-1,m),lcs(s,sr,n,m-1));
    }
public:
    int longestPalindromeSubseq(string s) {
        string sr=s;
        memset(dp,-1,sizeof dp);
        reverse(s.begin(),s.end());
        int n=s.length();
        return lcs(s,sr,n,n);
    }
};