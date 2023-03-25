using lli = long long int;
class Solution {
public:
    lli dfs(int node,vector<int>&vis,vector<int>adj[])
    {
        vis[node] = 1;
        lli tot = 0;
        for(auto i : adj[node]){
            if(!vis[i])
            {
                tot += dfs(i,vis,adj);
            }
        }
        return tot+1;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        lli ans = 0;
        vector<int>adj[n];
        for(int i =0;i < edges.size();i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        lli tot = 0;
        map<lli,lli>mp;
        vector<int>vis(n,0);
        for(int i = 0;i<n;i++)
        {
            if(!vis[i]){
                lli curr = dfs(i,vis,adj);
                tot+=curr;
                mp[i] = curr;
            }
        }
        for(auto i : mp )
        {
            ans += (tot - i.second) * i.second;
        }
        return ans/2;
    }
};