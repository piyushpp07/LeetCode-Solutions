// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    private :
    int mod = 1e9+7;
    int solve(string str,int i,int dp[])
    {
        if(i>=str.size())
        return 1;
        if(dp[i]!=-1)
        return dp[i];
        if(str[i]=='0')
        return 0;
        int a = 0,b=0;
        a = solve(str,i+1,dp);
        if(i+1<str.size())
        {
            string z = str.substr(i,2);
            int no = stoi(z);
            if(no<=26)
            {
                b = solve(str,i+2,dp);
            }
        }
        return dp[i]=(a%mod+b%mod)%mod;
    }
	public:
		int CountWays(string str){
		   int dp[10001];
		   memset(dp,-1,sizeof dp);
		   return solve(str,0,dp);
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends