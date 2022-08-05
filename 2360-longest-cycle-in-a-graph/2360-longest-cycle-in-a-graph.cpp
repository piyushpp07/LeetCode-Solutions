class Solution
{

    public:
        int dfs(int src, vector<int> &vis, vector<int> adj[])
        {
            vis[src] = 2;
            for (auto i: adj[src])
            {
                if (!vis[i])
                {
                    if(dfs(i, vis, adj))
                        return true;
                }
                else if (vis[i] == 2)
                    return 1;
            }
            vis[src] = 1;
            return 0;
        }
    int longestCycle(vector<int> &edges)
    {
        vector<int> adj[edges.size()];
        for (int i = 0; i < edges.size(); i++)
        {
            if (edges[i] != -1)
                adj[edges[i]].push_back(i);	//building the graph in opposite
        }
        int ans = -1;
        vector<int> vis(edges.size(), 0);
        for (int i = 0; i < edges.size(); i++)
        {
            if (vis[i])
                continue;
            if (edges[i] == -1) continue;
            else
            {
                int temp = dfs(i,vis,adj);
                if (temp)
                {
                    int cnt = 1;
                    int curr = i;
                    while (i != edges[curr]) curr = edges[curr], cnt++;

                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};