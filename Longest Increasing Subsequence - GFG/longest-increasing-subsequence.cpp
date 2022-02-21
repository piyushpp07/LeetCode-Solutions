// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{  
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int size, int a[])
    {   
       vector<int>dp(size,1);

        for(int i=0;i<size;i++)
        {
            for(int j=0;j<i;j++)
            {
              if(a[j]<a[i])
              dp[i] = max(dp[i],dp[j]+1);
            }
        }
        int ans = dp[0];
        for(int i=1;i<size;i++)
        {
            ans = max(dp[i],ans);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends