class Solution {
public:
    int vis[100001];
    void dfs(int node,vector<int>adj[],vector<int>&ans)
    {
        vis[node] = 1;
        for(auto curr : adj[node])
        {
            if(!vis[curr])
            {
                ans.push_back(curr);
                dfs(curr,adj,ans);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int>adj[n+1];
        map<int,int>mp;
        for(int i =0 ;i<roads.size();i++)
        {
            int src = roads[i][0];
            int des = roads[i][1];
            int cost = roads[i][2];
            adj[src].push_back(des);
            adj[des].push_back(src);
            if(mp.find(src)!=mp.end())
            mp[src] = min(mp[src],cost);
            else mp[src] = cost;
        }
       
        vector<int>ans;
        ans.push_back(1);
        memset(vis,0,sizeof vis);
        dfs(1,adj,ans);
        int cnt = INT_MAX;
        
        for(auto i : ans)
        {
            if(mp.find(i)!=mp.end())
            cnt = min(cnt,mp[i]);
        }
        
        return cnt;
    }
};