//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
   vector<string>ans;
    void solve(string &s,int idx,int cnt,string &p)
    {
        if(cnt == 4)
        {
            if(idx == s.size() ){
                ans.push_back(p);
            }
            return;
        }
        if(cnt < 4 && idx == s.size())
        return ;
        p += s[idx];
        if(cnt!=3)
          p += ".";
        solve(s,idx+1,cnt+1,p);
        p.pop_back();
        if(cnt!=3)
           p.pop_back();
        if(idx + 1 < s.size() && s[idx] != '0')
        {
            p += s[idx];
            p += s[idx+1];
            if(cnt!=3)
                p += ".";
            solve(s,idx+2,cnt+1,p);
            p.pop_back();
            p.pop_back();
            if(cnt!=3)
                p.pop_back();
        }
        if(idx + 2 < s.size() && s[idx] != '0' )
        {
            string z= "";
            z += s[idx];
            z += s[idx+1];
            z += s[idx+2];
            if(z >"0" && z<="255")
            {
                p += s[idx];
                p += s[idx+1];
                p += s[idx+2];
                if(cnt!=3)
                p += ".";
                solve(s,idx+3,cnt+1,p);
                p.pop_back();
                p.pop_back();
                p.pop_back();
                if(cnt!=3)
                p.pop_back();
            }  
        }
    }
    vector<string> genIp(string &s) {
                string p = "";
        solve(s,0,0,p);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends