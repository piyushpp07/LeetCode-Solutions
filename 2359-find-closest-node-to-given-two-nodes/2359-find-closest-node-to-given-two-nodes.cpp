class Solution
{
    public:
        vector<int> adj[100002];
    void bfs(vector<int> &a, int src)
    {
        vector<int> vis(a.size(), 0);
        queue<pair<int, int>> q;
        q.push({ 0,
            src });
        a[src] = 0;
        vis[src] = 1;
        while (!q.empty())
        {
            auto k = q.front();
            int d_x = k.first;
            int x = k.second;
            q.pop();
            for (auto i: adj[x])
            {
                if (!vis[i])
                {
                    a[i] = d_x + 1;
                    q.push({ a[i],
                        i });
                    vis[i] = 1;
                }
            }
        }
    }
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        if (node1 == node2)
            return node1;
        int n = edges.size();
        for (int i = 0; i < n; i++)
        {
            if (edges[i] != -1 && edges[i] != i)
                adj[i].push_back(edges[i]);
        }
        vector<int> a(n, INT_MAX);
        vector<int> b(n, INT_MAX);
        bfs(a, node1);
        bfs(b, node2);
        int ans = -1, dist = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (max(a[i], b[i]) < dist)
            {
                dist = max(a[i], b[i]);
                ans = i;
            }
        }

        return ans;
    }
};