// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

int dp[101][101][101];
int solve(string A, string B, string C, int i, int j, int k, int n1, int n2, int n3)
{
	if (i == n1 || j == n2 || k == n3)
		return 0;
	if (dp[i][j][k] != -1)
		return dp[i][j][k];
	else {
		if (A[i] == B[j] && B[j] == C[k])
			return dp[i][j][k] = 1 + solve(A, B, C, i + 1, j + 1, k + 1, n1, n2, n3);
		return dp[i][j][k] = max(max(solve(A, B, C, i + 1, j, k, n1, n2, n3),
		                             solve(A, B, C, i, j + 1, k, n1, n2, n3)),
		                         solve(A, B, C, i, j, k + 1, n1, n2, n3));
	}

}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{	memset(dp, -1, sizeof dp);
	return solve(A, B, C, 0, 0, 0, n1, n2, n3);
}