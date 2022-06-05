using pid = pair<double, int> ;
class Comp
{
    bool comp(pid a, pid b)
    {
        return a.second > b.second;
    }
};
class Solution
{

    public:
        double maxProbability(int n, vector<vector < int>> &edges, vector< double > &succProb, int start, int end)
        {
            vector<vector<pair<int, double>>> v(n);
            for (int i = 0; i < edges.size(); i++)
            {
                v[edges[i][0]].push_back({ edges[i][1],
                    succProb[i] });
                v[edges[i][1]].push_back({ edges[i][0],
                    succProb[i] });
            }
            vector<double> dis(n, INT_MIN);
            priority_queue<pid> pq;
            dis[start] = 1;
            pq.push({ 1,
                start });
            while (!pq.empty())
            {
                int ver = pq.top().second;
                double w = pq.top().first;
                pq.pop();
                for (auto edge: v[ver])
                {
                    int to = edge.first;
                    double wto = edge.second;

                    if (dis[ver] *wto > dis[to])
                    {
                        dis[to] = wto *dis[ver];
                        pq.push({ dis[to],
                            to });
                    }
                }
            }

            return dis[end] != INT_MIN ? dis[end] : 0;
        }
};