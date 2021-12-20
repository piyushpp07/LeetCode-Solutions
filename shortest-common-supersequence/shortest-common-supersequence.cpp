class Solution {
private:
    int dp[1001][1001];
    int lcs(string &s1,string &s2 , int n ,int m)
    {
         if(n==0||m==0)
             return 0;
         if(dp[n][m]!=-1)
             return dp[n][m];
          if(s1[n-1]==s2[m-1])
          {
              return dp[n][m]=1+lcs(s1,s2,n-1,m-1);
          }
          else{
              return dp[n][m]=max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));
          }
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        memset(dp,-1,sizeof(dp));
        int n= str1.length();
        int m= str2.length();
         string s="";
        int q=lcs(str1,str2,n,m);
        cout<<q;
       
        int i=n,j=m;
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                s+=str1[i-1];
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    s.push_back(str1[i-1]);
                    i--;
                }
                else
                    if(dp[i][j-1]>=dp[i-1][j])
                    {
                        s+=str2[j-1];
                        j--;
                    }
                
            }
            
          
        }
         while(i>0)
            {
                s+=str1[i-1];
                i--;
            }
            while(j>0)
            {
                s+=str2[j-1];
                j--;
                
            }
       

        reverse(s.begin(),s.end());
        return s;
    }
};