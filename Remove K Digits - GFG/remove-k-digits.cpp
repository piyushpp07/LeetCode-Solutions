//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(num.size()==1 && k ==1)
        return "0";
        int i = 0;
        stack<char>st;
        while(i < n)
        {
            char ch = num[i];
            while(st.size() && k && st.top() > ch)
            {
                k--;
                st.pop();
            }
            st.push(ch);
            i++;
        }
        while(k>0)
        {
            st.pop();
            k--;
        }
        string ans = "";
        while(st.size())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        i = 0;
        while(ans[i] == '0')
        {
            i++;
        }
        return ans.substr(i,ans.size())!="" ? ans.substr(i,ans.size()):"0";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends