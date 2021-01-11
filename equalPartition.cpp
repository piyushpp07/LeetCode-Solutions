 int equalPartition(int N, int arr[])
    {
    vector<int> v(N+1);
     int sum=0;
     for(int i=0; i<N; i++)
     {v[i+1]=arr[i];
     sum+=arr[i];}
     if(sum%2!=0)
     return 0;
     else{
         sum=sum/2;
     bool dp[N+1][sum+1];
        for(int i=0; i<=sum; i++)
        dp[0][i]=false;
        for(int i=0; i<=N; i++)
        dp[i][0]=true;  //with zero element we can make sum zero
        for(int i=1; i<=N; i++){
            for(int j=1; j<=sum; j++){
                if(v[i]>j)
                dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j-v[i]]||dp[i-1][j];
            }
        }
         return dp[N][sum];
    }}
