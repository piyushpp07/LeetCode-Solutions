class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {

        vector<pair<int,int>>v[n];
        for(int i = 0;i<redEdges.size();i++)
        {
            v[redEdges[i][0]].push_back({redEdges[i][1],1});
           
        }
        for(int i = 0;i<blueEdges.size();i++)
        {
            v[blueEdges[i][0]].push_back({blueEdges[i][1],2});
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<vector<int>>dis(n,vector<int>(3,INT_MAX));
        dis[0][0] = 0;
        while(q.size())
        {
        
            auto ele = q.front();
            q.pop();
            int curr_node = ele.first;
            int prev = ele.second;
            for(auto i : v[curr_node])
            {
                if(prev == i.second)
                    continue;
                if(dis[i.first][i.second] ==  INT_MAX )
                {
                    dis[i.first][i.second] = dis[curr_node][prev] + 1;
                    q.push({i.first,i.second});
                }
            }
        }
        vector<int>ans(n,0);
        for(int i = 1;i<n;i++)
        {
            ans[i] = min(dis[i][1],dis[i][2]);
            if(ans[i] == INT_MAX)
                ans[i] = -1;
        }
        return ans;
        
    }
};


