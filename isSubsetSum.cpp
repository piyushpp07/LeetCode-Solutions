//recursive + memorise
int isSubsetSum(int arr[],int k,int n)
{
    int dp[n+1][k+1];
    if(k==0)
    return dp[n][k]=1;
    if(n=0)
    return dp[n][k]=1;
    else if(dp[n][k]!=0)
    return dp[n][k];
    else {
           if(arr[n-1]>k)
           return dp[n][k]=isSubsetSum(arr,k,n-1);
           else 
            return dp[n][k]=isSubsetSum(arr,k-arr[n-1],n-1)||isSubsetSum(arr,k,n-1);
         }
         return dp[n][k];
}

//dp
int isSubsetSum(int arr[],int k,int n)
{
    int dp[n+1][k+1];
     for(int i=0;i<=n;i++)
      {
      for(int j=0;j<=k;j++)
      {
      if(i==0)
      dp[i][j]=0;
      else if(j==0)
      dp[i][j]=1;
      else if(arr[i-1]<=j)
      dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
      else
      dp[i][j]=dp[i-1][j];
      }
      }
      return dp[n][k];
}
