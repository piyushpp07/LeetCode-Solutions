// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 


 // } Driver Code Ends
class Solution
{   private:
    int lcs(string s1,string s2,int i ,int j,vector<vector<int>>&dp)
    {
        if(i == s1.length()|| j == s2.length())
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(s1[i]==s2[j])
        return dp[i][j] = 1 + lcs(s1,s2,i+1,j+1,dp);
        else{
            return dp[i][j]=max(lcs(s1,s2,i+1,j,dp),lcs(s1,s2,i,j+1,dp));
        }
    }
    public:
    int build_bridges(string str1, string str2)
    { int n = str1.length();
      int m = str2.length();
      vector<vector<int>>dp(n,vector<int>(m,-1));
      return lcs(str1,str2,0,0,dp);
    }
};

// { Driver Code Starts.
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        string str1,str2;
        cin >> str1 >> str2;
        Solution obj;
        cout<<obj.build_bridges(str1,str2)<<endl;
    } 
    return 0;
} 
  // } Driver Code Ends