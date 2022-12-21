//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(int n,int m,string &s,string &t,vector<vector<int>>&dp)
    {
        if(n<0)
        return m+1;
        if(m<0)
        return n+1;
        if(dp[n][m]!=-1)
        return dp[n][m];
        if(s[n] == t[m])
        return dp[n][m] =  solve(n-1,m-1,s,t,dp);
        return dp[n][m] =  1 + min({solve(n-1,m,s,t,dp),solve(n,m-1,s,t,dp),solve(n-1,m-1,s,t,dp)});
    }
    int editDistance(string s, string t) {
        int n = s.size(),m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n-1,m-1,s,t,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends