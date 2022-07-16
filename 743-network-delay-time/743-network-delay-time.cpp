class Solution
{

    public:
        int networkDelayTime(vector<vector < int>> &t, int n, int k)
        {
            vector<vector<pair<int, int>>> adj(n + 1);
            for (int i = 0; i < t.size(); i++)
            {
                adj[t[i][0]].push_back({ t[i][1],
                    t[i][2] });
            }
            vector<int> dis(n + 1, INT_MAX);
            dis[k] = 0;
            dis[0] = 0;
            priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({ 0,
                k });
            while (!pq.empty())
            {
                int v = pq.top().second;
                int d_v = pq.top().first;
                pq.pop();
                if (dis[v] != d_v)
                    continue;
                for (auto i: adj[v])
                {
                    int to = i.first;
                    int d_to = i.second;
                    if (dis[to] > dis[v] + d_to)
                    {
                        dis[to] = dis[v] + d_to;
                        pq.push({ dis[to],
                            to });
                    }
                }
            }
            int ans = INT_MIN;
            for (int i = 0; i < dis.size(); i++)
            {
                if (dis[i] > ans) ans = dis[i];
            }
            if (ans == INT_MAX)
                return -1;
            return ans;
        }
};