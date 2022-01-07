class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        queue<int>q;
        int in[n];
        memset(in,0,sizeof in);
        vector<vector<int>>graph(n);
        for(auto it :pre)
        {
            graph[it[1]].push_back(it[0]);
            in[it[0]]++;
        }
        for(int i=0;i<n;i++)
        {
           if(in[i]==0)
               q.push(i);
        }
        vector<int>topo;
        while(!q.empty())
        {
            int node = q.front();
            topo.push_back(node);
            q.pop();
            for(auto it : graph[node])
            {
                in[it]--;
                if(in[it]==0)
                {
                    q.push(it);
                }
            }
        }

        if(topo.size()==n) return true;
        return false;
    }
};