// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
    private:
int solve(int arr[], int i, int n, int dp[])
{   if (i >= n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int a = INT_MIN, b = INT_MIN;
    a = solve(arr , i + 1, n, dp);
    b = arr[i] + solve(arr, i + 2, n, dp);
    return dp[i] = max(a, b);
}
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    int dp[n];
	    memset(dp,-1,sizeof dp);
	  return solve(arr,0,n,dp);
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends