//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
            
            deque<int>dq;
            for(int i = 0;i<k;i++)
            {
                while(dq.size() && arr[dq.back()] <= arr[i])
                dq.pop_back();
                dq.push_back(i);
            }
            vector<int>v;
            for(int i = k ;i<n;i++)
            {
                v.push_back(arr[dq.front()]);
                while(dq.size() && dq.front() <= i - k)
                dq.pop_front();
                while(dq.size() && arr[dq.back()] <= arr[i])
                dq.pop_back();
                dq.push_back(i);
            }
            v.push_back(arr[dq.front()]);
            
            return v;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends