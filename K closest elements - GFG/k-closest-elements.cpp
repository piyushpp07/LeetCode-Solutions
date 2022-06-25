// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
bool comp(pair<int,int> &a, pair<int,int>&b)
{  
    if(a.first!= b.first)
    return a.first<b.first;
    else
    return a.second>b.second;
}
class Solution{   
public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
      vector<pair<int,int>>v;
      for(int i=0;i<n;i++)
      {
          v.push_back({abs(x-arr[i]),arr[i]});
      }
      sort(v.begin(),v.end(),comp);
      vector<int>ans;
      for(int i = 0;ans.size()<k;i++)
      {
            if(v[i].first != 0)
           {
               ans.push_back(v[i].second);
               }   
      }
      return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends