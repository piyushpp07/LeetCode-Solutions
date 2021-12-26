class Solution {
    
private:
    int dp[1001][1001];
    bool helper(string &s,int l , int r,vector<int>&ans)
    {
     if(dp[l][r]!=-1)
          return dp[l][r];
      if(l>=r)
          return true;
 
    bool found=false;
    if(s[l]==s[r])
    {
        found=true&&helper(s,l+1,r-1,ans);
    }
    helper(s,l+1,r,ans);
    helper(s,l,r-1,ans);
    if(found&&(r-l+1)>ans[2])
    {
        ans={l,r,(r-l+1)};
    }
    dp[l][r]=found;
    return found;
    }
  
public:
    string longestPalindrome(string s) {
     memset(dp,-1,sizeof dp);
     int n=s.size();
     vector<int>ans={0,0,1};
     helper(s,0,n-1,ans);
    return s.substr(ans[0],ans[2]);
     
    }
};