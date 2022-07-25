//dp no of ways to make given sum yup
    long long int count( int c[], int n, int total)
    {
        long int dp[n+1][total+1];
    for(int i=0;i<=n;i++)
       {
           for(int j=0;j<=total;j++)
           {
               
               if(i==0)dp[i][j]=0;
               else if(j==0)dp[i][j]=1;
               else if(c[i-1]>j)
               {
               dp[i][j]=dp[i-1][j];
               }
               else
               dp[i][j]=dp[i-1][j]+dp[i][j-c[i-1]];
           }
       }
       return dp[n][total];
    }
    
 //memorised correction is needed here if you can try
 int dp[1001][1001];
long long int count( int S[], int m, int n )
    {
       if(n==0)
       return dp[n][m]=0;
       else if (m==0)
       return dp[n][m]=1;
       else if (dp[n][m]!=-1)
       return dp[n][m];
       else if (S[n-1]>m)
       return dp[n][m]=count(S,m,n-1);
       else 
       return dp[n][m]=count(S,m-S[n],n-1)+count(S,m,n-1);
    }
