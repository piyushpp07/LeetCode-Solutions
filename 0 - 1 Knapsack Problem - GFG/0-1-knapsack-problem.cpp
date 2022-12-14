//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int dp[1001][1001];
    //Function to return max value that can be put in knapsack of capacity W.
    int f(int w,int wt[],int val[],int idx)
    {
        if(idx == 0 )
        {
            if(w >= wt[idx])
            return val[idx];
            else 
            return 0;
        }
        if(w == 0)
        return 0;
        if(dp[idx][w]!=-1)
        return dp[idx][w];
        int pick = 0,notpick = 0;
        if(w>=wt[idx])
        pick = val[idx] + f(w - wt[idx] ,wt,val,idx - 1);
        notpick = f(w,wt,val,idx-1);
        return dp[idx][w] =  max(pick,notpick);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       memset(dp,-1,sizeof dp);
       return f(W,wt,val,n-1);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends