//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
bool prime[100001];
void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    
    memset(prime, true, sizeof(prime));
  
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
  
    // Print all prime numbers

}
 
class Solution {
  public:
  
    vector<int> leastPrimeFactor(int n) {
        vector<int>ans;
        SieveOfEratosthenes(n+1);
        ans.push_back(0);
        if(n >= 1)
        ans.push_back(1);
        for(int i =1;i<=n;i++)
        {
            for(int j = 2;j<=n;j++)
            {
                if(prime[j]&&i%j == 0)
                {
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends