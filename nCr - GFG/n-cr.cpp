//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
long long int mod = 1e9+7;
class Solution{
public:
    int nCr(int n, int r){
        vector<long long int > c(r+1,0);
        c[0] = 1;
        for(int i = 1;i<=n;i++)
        {
            for(int j = min(r,i);j>0;j--)
            {
                c[j] = (c[j]+c[j-1])%1000000007;
            }
        }
        return c[r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends