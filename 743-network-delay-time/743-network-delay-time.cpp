class Solution
	{

	public:
		int networkDelayTime(vector<vector < int>> &times, int n, int k)
		{
			vector<vector<pair<int, int>>> adj(n + 1);
			for (int i = 0; i < times.size(); i++)
				adj[times[i][0]].push_back({ times[i][1],
				                             times[i][2]
				                           });
			using ppi = pair<int, int> ;

			vector<int> d(n + 1, INT_MAX);

			priority_queue<ppi, vector <ppi>, greater < ppi>> q;
			q.push({ 0, k});

			d[k] = 0;
			d[0] = 0;
			while (!q.empty())
			{
				int v = q.top().second;
				int d_v = q.top().first;
				q.pop();
				if (d_v != d[v])
					continue;
				for (auto edge : adj[v])
				{
					int to = edge.first;
					int len = edge.second;
					if (d[to] > d[v] + len)
					{
						d[to] = d[v] + len;
						q.push({ d[to], to});
					}
				}
			}
			int ans = INT_MIN;
			for (int i = 0; i < d.size(); i++)
				if (d[i] > ans) ans = d[i];
			if (ans == INT_MAX)
				return -1;
			else return ans;
		}
	};