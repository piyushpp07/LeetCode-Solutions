//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{

public:
    bool solve(string &s,int idx,vector<int>&dp,set<string>&st)
    {
        if(idx == s.size())
        return true;
        if(dp[idx]!=-1)
        return dp[idx];
        bool ans = false;
        string k = "";
        for(int i = idx;i<s.size();i++)
        {
            k += s[i];
            if(st.find(k)!=st.end())
              ans = ans || solve(s,i+1,dp,st);  
        }
        return dp[idx] = ans;
    }
    int wordBreak(string s, vector<string> &wordDict) {
       set<string>st;
       for(auto i : wordDict)
       st.insert(i);
       vector<int>dp(s.size(),-1);
       return solve(s,0,dp,st);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends