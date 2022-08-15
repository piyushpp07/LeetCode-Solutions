class Solution
{
    public:
        bool able(string s, string t)
        {
            int c = 0;
            for (int i = 0; i < s.length(); i++)
                c += (s[i] != t[i]);
            return c == 1;
        }
    int bfs(vector<vector < int>> g, int n, int start, int end) {
        queue<pair<int,int>>q;
        q.push({start,1});
        vector<int>vis(n,0);
        while(!q.empty())
        {
            auto d_p = q.front();
            q.pop();
            int node = d_p.first;
            int dis = d_p.second;
            if(node == end)
                return dis;
            for(auto i : g[node])
            {
                if(vis[i] == 0)
                {
                    q.push({i,dis+1});
                    vis[i]  = 1;
                }
            }
        }
        return -1;
        
        
    }
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int n = wordList.size(), start = -1, end = -1;
        vector<vector < string>> ANS;
        for (int i = 0; i < n; i++)
        {
            if (wordList[i] == beginWord)
                start = i;
            if (wordList[i] == endWord)
                end = i;
        }

       	// if endWord doesn't exist, return empty list
        if (end == -1)
            return 0;

       	// if beginWord doesn't exist, add it in start of WordList
        if (start == -1)
        {
            wordList.emplace(wordList.begin(), beginWord);
            start = 0;
            end++;
            n++;
        }
        vector<vector < int>> g(n, vector<int> ());
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (able(wordList[i], wordList[j]))
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
        int sol =  bfs(g, n, start, end) ;
        return sol == -1 ? 0 : sol;
    }
};