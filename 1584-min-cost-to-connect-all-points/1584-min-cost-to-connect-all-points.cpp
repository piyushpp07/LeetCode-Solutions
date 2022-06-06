class Solution
{
    private:
        int parent[1001];
    vector<pair<int, pair<int, int>>> adj;
    void make(int n)
    {
        parent[n] = n;
    }
    int find(int a)
    {
        if (a == parent[a]) return a;
        return find(parent[a]);
    }
    void Union(int a, int b)
    {
        int m = find(a);
        int n = find(b);
        if(m!=n)
        parent[m] = n;
    }
    public:
        int minCostConnectPoints(vector<vector < int>> &points)
        {
            int n = points.size();

            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                    adj.push_back({ d,
                        {
                            i,
                            j
                        } });
                }
            }
            sort(adj.begin(), adj.end());
            for (int i = 0; i < n; i++)
                make(i);
            int cost = 0;
            for (auto edge: adj)
            {
                int wt = edge.first;
                int a = edge.second.first;
                int b = edge.second.second;
                if (find(a) == find(b)) continue;
                else
                {
                    Union(a, b);
                    cost += wt;
                }
            }
            return cost;
        }
};