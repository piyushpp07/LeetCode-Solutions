// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++


class Solution
{   private:    
    int dp[1001][1001];
    int helper(int coins[],int n,int value)
    {
        if(value==0)
        return dp[n][value] = 1;
        
        if(n==0)
        return  0;
        
        if(dp[n][value]!=-1)
        return dp[n][value];
    
        if(value<coins[n-1])
        return dp[n][value] = helper(coins,n-1,value);
        return dp[n][value] = helper(coins,n,value-coins[n-1])+helper(coins,n-1,value);
    }

    public:
    //Function to find out the number of ways to use the coins to
    //sum up to a certain required value.
    long long numberOfWays(int coins[],int n,int value)
    {
      memset(dp,-1,sizeof(dp));
      return helper(coins,n,value);
    }
};


// { Driver Code Starts.


int main() {
    
    //taking total count of testcases
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    //taking value
	    int value;
	    cin>>value;
	    
	    //taking number of coins
	    int numberOfCoins;
	    cin>>numberOfCoins;
	    int coins[numberOfCoins];
	    
	    //inserting coins to the array
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    Solution obj;
	    //calling function numberOfWays
	    cout<<obj.numberOfWays(coins,numberOfCoins,value)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends