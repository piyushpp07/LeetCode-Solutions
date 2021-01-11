//memorised
int no(int a[],int k,int n)
{
int dp[n+1][k+1];
memset(dp,-1,sizeof(dp));
if(n==0)
return dp[n][k]=0;
else if (k==0)
return dp[n][k]=1;
else if(dp[n][k]!=-1)
return dp[n][k];
else if(k>=a[n-1])
return dp[n][k]=no(a,k-a[n-1],n-1)+no(a,k,n-1);
else
return dp[n][k]=no(a,k,n-1);
}
//dp
int no(int a[],int k,int n)
{
int dp[n+1][k+1];
memset(dp,-1,sizeof(dp));
for(int i=0;i<=n;i++)
{
  for(int j=0;<=k;j++)
 {
  if(i==0)
    dp[i][j]=0;
  else if (j==0)
    dp[i][j]=1;
  else if(k>=a[n-1])
    dp[n][k]=dp[n-1][k-a[n-1]]+dp[n-1][k];
  else
   dp[n][k]=dp[n-1][k];
  }
 }
 return dp[n][k];
}
