class Solution {
    int ans = INT_MAX;
    void solve(int idx,vector<int>&cookies,vector<int>&bag,int k)
    {
            if(idx >= cookies.size())
            {
                    int till = 0;
                    for(int i : bag)
                           till = max(till,i);
                    ans = min(ans,till);
                    return ;
            }
            for(int i = 0;i<k;i++)
            {
                    bag[i] += cookies[idx];
                    solve(idx+1,cookies,bag,k);
                    bag[i] -= cookies[idx];
            }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
      vector<int>bag(k,0);  
      solve(0,cookies,bag,k);
            return ans;
        
    }
};