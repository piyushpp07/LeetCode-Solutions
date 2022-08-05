class Solution
{
    public:
        bool isCycle(int node, vector<int> &vis, vector<int> adj[])
        {
            vis[node] = 2;

            for (auto x: adj[node])
            {
                if (!vis[x])
                {
                    if (isCycle(x, vis, adj)) return true;
                }
                else if (vis[x] == 2) return true;
            }

            vis[node] = 1;
            return false;
        }

    int longestCycle(vector<int> &edges)
    {
        int n = edges.size();
        vector<int> adj[n];

        for (int i = 0; i < n; i++)
        {
            int u = i;
            int v = edges[i];

            if (v == -1) continue;
            adj[v].push_back(u);
        }

        int maxi = -1;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (vis[i]) continue;
            if (edges[i] == -1) continue;

            bool temp = isCycle(i, vis, adj);

            if (temp)
            {
                int cnt = 1;
                int curr = i;
                while (i != edges[curr]) 
                    curr = edges[curr], cnt++;

                maxi = max(maxi, cnt);
            }
        }

        return maxi;
    }
};