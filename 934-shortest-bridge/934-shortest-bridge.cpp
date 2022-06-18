class Solution
{
    public:

        vector<int> dx = { -1,
            0,
            1,
            0
        };
    vector<int> dy = { 0,
        1,
        0,
        -1
    };

    void dfs(queue<pair<int,int>> &q, int sr, int sc, vector<vector< bool >> &vis, vector< vector< int>> &v1)
    {
        vis[sr][sc] = true;
        q.push({sr,sc});
        for (int i = 0; i < 4; ++i)
        {
            int r = sr + dx[i];
            int c = sc + dy[i];
            if (r < 0 or c < 0 or r >= v1.size() or c >= v1[0].size()) continue;
            if (v1[r][c] == 0) continue;
            if (!vis[r][c]) dfs(q, r, c, vis, v1);
        }
    }

    int shortestBridge(vector<vector < int>> &v1)
    {
        queue<pair<int, int>> q;
        bool flag = false;
        vector<vector < bool>> vis(v1.size(), vector<bool> (v1[0].size()));
        for (int i = 0; i < v1.size(); ++i)
        {
            for (int j = 0; j < v1[0].size(); ++j)
            {
                if (v1[i][j] == 1)
                {
                    flag = true;
                    dfs(q, i, j, vis, v1);
                    break;
                }
            }
            if (flag) break;
        }
        int level = 0;
        while (q.size() > 0)
        {
            int size = q.size();
            while (size--)
            {
                pair rem = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i)
                {
                    int r = rem.first + dx[i];
                    int c = rem.second + dy[i];
                    if (r < 0 or c < 0 or r >= v1.size() or c >= v1[0].size()) continue;
                    if (vis[r][c]) continue;
                    if (v1[r][c]) return level;
                    vis[r][c] = true;
                    q.push({r,c});
                }
            }
            ++level;
        }
        return -1;
    }
};