class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans = 0;
        vector<int>adj[n];
        for(int i = 0;i<informTime.size();i++)
        {
            if(manager[i] != -1)
                adj[manager[i]].push_back(i);
        }

        queue<pair<int,int>>q;
        q.push({headID,0});
        
        while(q.size())
        {
            int sz = q.size();
            for(int i = 0;i<sz;i++){
                auto l = q.front();
                q.pop();
                ans = max(l.second,ans);
                for(int j = 0;j<adj[l.first].size();j++)
                {
                    q.push({adj[l.first][j],l.second + informTime[l.first]});
                }
            }
        }
        return ans;
        
    }
};