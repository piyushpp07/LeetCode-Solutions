class Solution {
private:
void dfs(int n,vector<int>&v,vector<vector<int>>&adj)
{
    v[n]=1;
    for(auto i:adj[n]){
                if(!v[i])
            dfs(i,v,adj);
    }

}
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n= rooms.size();
        vector<int>vis(n,0);
        vector<vector<int>>graph(n);
        for(int i=0;i<n;i++)
        {
            for(auto j: rooms[i])
            {
                graph[i].push_back(j);
            }
        }
        int cc=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i]){
                cc++;
                dfs(i,vis,graph);
            }
        }
        if(cc>1)
            return false;
        return true;
        
    }
};